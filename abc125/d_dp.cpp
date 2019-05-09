#include <cstdio>
#include <climits>
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
#include <numeric>
#include <bitset>
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
const int INF = 1e6;
const long long int LINF= 1e16;
int main() {
    LL n;
    cin >> n;
    vector<LL> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<vector<LL >> dp(n + 1, vector<LL>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = - LINF;
    for (LL i = 1; i < n + 1; i++) {
        dp[i][0] = max(dp[i - 1][0] + a[i - 1], dp[i - 1][1] - a[i - 1]);
        dp[i][1] = max(dp[i - 1][0] - a[i - 1], dp[i - 1][1] + a[i - 1]);
    }

    cout << dp[n][0] << endl;
    return 0;
}
