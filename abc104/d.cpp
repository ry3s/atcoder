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

const LL MOD = 1e9 + 7;
long long dp[210000][5];

void add(long long &a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
    string s; cin >> s;

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    rep(i, s.size()) {
        rep(j, 5) {
            if (s[i] != '?') add(dp[i + 1][j], dp[i][j]);
            else add(dp[i + 1][j], dp[i][j] * 3 % MOD);
        }

        if (s[i] == 'A' || s[i] == '?') add(dp[i+1][1], dp[i][0]);
        if (s[i] == 'B' || s[i] == '?') add(dp[i+1][2], dp[i][1]);
        if (s[i] == 'C' || s[i] == '?') add(dp[i+1][3], dp[i][2]);
    }
    cout << dp[s.size()][3] << endl;
}
