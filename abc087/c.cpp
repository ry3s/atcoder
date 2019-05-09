#include <cstdio>
#include <climits>
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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define mod 1000000007
using namespace std;
typedef long long int LL;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > a(2, vector<int>(n));

    rep(i, 2) {
        rep(j, n) {
            cin >> a[i][j];
        }
    }

    vector<vector<int> > dp(2, vector<int>(n));
    dp[0][0] = a[0][0];
    for(int i = 1; i < n; i++) {
        dp[0][i] = a[0][i] + dp[0][i - 1];
    }
    dp[1][0] = a[0][0] + a[1][0];

    for (int i = 1; i < n; i++) {
        dp[1][i] = a[1][i] + max(dp[0][i], dp[1][i - 1]);
    }
    // rep(i, 2) {
    //     rep(j, n) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[1][n - 1] << endl;
    return 0;
}
