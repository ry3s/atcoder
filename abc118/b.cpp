#include <cstdio>
#include <climits>
#include <cstdlib>
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

int main() {
    int n, m; cin >> n >> m;
    vector<set<int>> a(n);
    rep(i, n) {
        int k; cin >> k;
        rep(j, k) {
            int x; cin >> x;
            a[i].insert(x);
        }
    }
    set<int> res;
    res = a[0];
    rep(i, n - 1) {
        auto tmp = res;
        res.clear();
        set_intersection(tmp.begin(), tmp.end(),
                         a[i + 1].begin(), a[i + 1].end(),
                         inserter(res, res.end()));
    }
    cout << res.size() << endl;
    return 0;
}
