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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

LL dp[101010][3];
int main() {
    int n;
    cin >> n;
    vector<vector<int> > v(n, vector<int>(3, 0));
    rep(i, n) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    rep(i, 3) {
        dp[0][i] = v[0][i];
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = v[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = v[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = v[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }
    LL res = 0;
    rep(i, 3) {
        res = max(res, dp[n - 1][i]);
    }
    cout << res << endl;
    return 0;
}
