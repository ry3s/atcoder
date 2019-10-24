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

int64_t dp[128][512] = {};
// dp[i][j] := i 個使用して重さの総和が j + w_0 * i となるときの価値の最大値

int main() {
    int N; int64_t W; cin >> N >> W;
    vector<pair<int64_t, int64_t>> goods(N);
    rep(i, N) {
        int64_t w, v; cin >> w >> v;
        goods[i] = {w, v};
    }

    int64_t sum = 0;
    rep(i, N) {
        int64_t ww = goods[i].first - goods[0].first;
        // 荷物iを複数回使わないように逆に回す
        for (int j = i; j >= 0; --j) { // 荷物iを含まないでj個
            for (int k = sum; k >= 0; --k) { // 荷物iを含まない時の重さがk
                dp[j + 1][k + ww] =
                    max(dp[j + 1][k + ww],
                        dp[j][k] + goods[i].second);
            }
        }
        sum += ww;
    }
    int64_t ans = 0;
    rep(i, N + 1) {
        rep(j, sum + 1) {
//            debug(goods[0].first * i + j);
            if (goods[0].first * i + j > W) continue;

            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}
