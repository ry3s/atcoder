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
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }

    UnionFind uf(n);
    vector<int> cnt(n, 1);

    rep(i, n) {
        int j = a[i];
        if (not uf.is_same(i, j)) {
            int sm = cnt[uf.root(i)] + cnt[uf.root(j)];
            uf.merge(i, j);
            cnt[uf.root(i)] = sm;
        }
    }
    int ans = 0;
    rep(i, n) if (uf.root(i) == i) {
        if (cnt[i] % 2 == 1) {
            ans = -1;
            break;
        }

        ans += cnt[i] / 2;
    }
    cout << ans << endl;
}
