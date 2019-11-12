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
template <typename T> inline constexpr void chmin(T &a, T b) { if (a > b) a = b; }

using LL = long long;
using ULL = unsigned long long;
long long dp[51][510][510];
// dp[i 個数][j A の重さ][k B の重さ] := 価格の最小値
const long long INF = (1LL << 60);

int main() {
    int n, ma, mb; cin >> n >> ma >> mb;
    vector<tuple<int, int, int>> drugs(n);
    rep(i, n) {
        int a, b, c;
        cin >> a >> b >> c;
        drugs[i] = {a, b, c};
    }

    rep(i, 51) rep(j, 500) rep(k, 500) {
        dp[i][j][k] = INF;
    }
    dp[0][0][0] = 0;
    rep(i, n) {
        rep(wa, 500) {
            rep(wb, 500) {
                if (dp[i][wa][wb] >= INF) continue;
                int a, b, c;
                tie(a, b, c) = drugs[i];

                chmin(dp[i + 1][wa][wb],
                      dp[i][wa][wb]);

                chmin(dp[i + 1][wa + a][wb + b],
                      dp[i][wa][wb] + c);
            }
        }
    }
    long long ans = INF;
    for (int wa = 1; wa < 500; wa++) {
        for (int wb = 1; wb < 500; wb++) {
            if (wa * mb != wb * ma) continue;

            chmin(ans, dp[n][wa][wb]);
        }
    }
    if (ans < INF) cout << ans << endl;
    else cout << -1 << endl;
}
