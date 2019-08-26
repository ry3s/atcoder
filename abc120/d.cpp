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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
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
    LL n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    UnionFind uf(n);
    LL cur = n * (n - 1) / 2;
    vector<LL> res;
    rep(i, m) {
        res.push_back(cur);

        int x = a[m - 1 - i]; int y = b[m - 1 - i];
        if (uf.is_same(x, y)) continue;

        LL sa = uf.size(x); LL sb = uf.size(y);
        cur -= sa * sb;
        uf.merge(x, y);
    }
    reverse(res.begin(), res.end());
    for (auto x : res) {
        cout << x << endl;
    }
    return 0;
}
