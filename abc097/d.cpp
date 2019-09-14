#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
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
    int n, m; cin >> n >> m;
    vector<int> p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    UnionFind uf(n);
    rep(i, m) {
        int x, y; cin >> x >> y;
        uf.merge(x, y);
    }
    int ans = 0;
    rep(i, n) {
        if (i == p[i]) {
            ans++;
            continue;
        }

        if (uf.is_same(i, p[i])) ans++;
    }
    cout << ans << endl;
    return 0;
}
