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

LL dp[100001][13];
const ULL MOD = 1000000007LL;

int main() {
    string str;
    cin >> str;

    dp[0][0] = 1;
    rep(i, str.length()) {
        int c = 0;
        if (str[i] == '?') c = -1;
        else c = str[i] - '0';

        rep(j, 10) {
            if (c != -1 and c != j) continue;

            rep(ki, 13) {
                dp[i + 1][(ki * 10 + j) % 13] += dp[i][ki];
            }
        }
        rep(j, 13) {
            dp[i + 1][j] %= MOD;
        }
    }
    LL res = dp[str.length()][5];
    cout << res << endl;
    return 0;
}
