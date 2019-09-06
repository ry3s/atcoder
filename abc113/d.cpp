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

const int MOD = 1000000007;
int h, w, k;

LL solve() {
    --k;

    vector<vector<LL>> dp(h + 1, vector<LL>(w, 0));
    // dp[i][j] := 縦棒をうえから i 刻み分についての入れ方のうち、1 から
    // スタートして j で終わるようなものの個数

    dp[0][0] = 1;
    rep(i, h) {
        rep(j, w) {
            rep(bit, 1 << (w - 1)) {
                bool ok = true;

                rep(k, w - 2) {
                    if ( (bit & (1 << k)) and (bit & (1 << (k + 1))) ) {
                        ok = false;
                    }
                }

                if (not ok) continue;
                int nj = j;
                if (bit & (1 << j)) nj = j + 1;
                else if (j > 0 and (bit & (1 << (j - 1)))) nj = j - 1;
                dp[i + 1][nj] += dp[i][j] % MOD;
                dp[i + 1][nj] = dp[i + 1][nj] % MOD;
            }
        }
    }
    return dp[h][k];
}
int main() {
    cin >> h >> w >> k;
    cout << solve() << endl;
    return 0;
}
