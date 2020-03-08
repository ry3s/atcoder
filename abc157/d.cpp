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
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
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
    int n, m, k; cin >> n >> m >> k;
    vector<set<int>> sets(n);
    UnionFind uf(n);

    rep(i, m) {
        int a, b; cin >> a >> b;
        --a, --b;
        sets[a].insert(b);
        sets[b].insert(a);
        uf.merge(a, b);
    }

    rep(i, k) {
        int c, d; cin >> c >> d;
        --c, --d;
        if (!uf.is_same(c, d)) continue;
        sets[c].insert(d);
        sets[d].insert(c);
    }

    rep(i, n) {
        int num = uf.size(i) - 1 - sets[i].size();
        cout << num << " ";
    }
    cout << endl;
}
