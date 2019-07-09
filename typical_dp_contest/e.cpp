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

// dp[0][i][j] ::= （下から i 桁までの数で， mod が j であるものの数）
// dp[1][i][j] ::= （下から i 桁までの数で， mod が j かつ，各桁が n の同じ桁の数以下のもののであるものの数）
LL dp[2][10004][102];
int main() {
    const LL MOD = 1e9 + 7;
    int d;
    string str;
    cin >> d >> str;
    int n = str.size();
    dp[0][0][0] = dp[1][0][0] = 1LL;
    rep(i, n) rep(j, d) {
        rep(k, 10) {
            int digit = (int)(str[n - 1 - i] - '0');
            (dp[0][i + 1][(j + k) % d] += dp[0][i][j]) %= MOD;
            (dp[1][i + 1][(j + k) % d] += (k > digit ? 0LL : dp[k == digit][i][j])) %= MOD;
        }
    }
    cout << dp[1][n][0] - 1LL << endl;
    return 0;
}
