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

int main() {
    int n, m; cin >> n >> m;
    vector<LL> mini(1 << n, (1LL << 60)), dp(1 << n, (1LL << 60));

    rep(i, m) {
        int mask = 0;
        int x, y; cin >> x >> y;
        rep(j, y) {
            int r; cin >> r;
            mask |= 1 << (r - 1);
        }
        mini[mask] = min(mini[mask], (LL)x);
    }
    dp[0] = 0;
    rep(x, 1 << n) rep(y, 1 << n) {
        dp[x | y] = min(dp[x | y], dp[x] + mini[y]);
    }
    if (dp[(1 << n) - 1] == (1LL << 60)) {
        cout << -1 << endl;
    } else {
        cout << dp[(1 << n) - 1] << endl;
    }
}
