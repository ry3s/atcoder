#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;
struct UnionFind {
    vector<int> par;

    UnionFind(int n) {
        par.assign(n, -1);
    }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    bool is_same(int x, int y) {
        return root(x) == root(y);
    }
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x) {
        return -par[root(x)];
    }
};
int main() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> persons(n);
    rep(i, n) {
        int a; cin >> a;
        rep(j, a) {
            int x, y; cin >> x >> y;
            --x;
            persons[i].push_back({x, y});
        }
    }
    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        UnionFind uf(n);
        vector<int> oks, ngs;
        rep(i, n) {
            if (bit & (1 << i)) oks.push_back(i);
            else ngs.push_back(i);

        }

        int index = 0;
        while (index + 1 < oks.size()) {
            uf.merge(oks[index], oks[index + 1]);
            index++;
        }
        index = 0;
        while (index + 1 < ngs.size()) {
            uf.merge(ngs[index], ngs[index + 1]);
            index++;
        }
        bool ok = true;
        rep(i, n) {
            for (auto p: persons[i]) {
                if (p.second == 1
                    && (bit & (1 << i))) {
                    if (!uf.is_same(i, p.first)) {
                        ok = false;
                        break;
                    }
                } else if (p.second == 0
                           && (bit & (1 << i))) {
                    if (uf.is_same(i, p.first)) {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok) break;
        }
        if (ok) {
            ans = max(ans, (int)oks.size());
        }
    }
    cout << ans << endl;
}
