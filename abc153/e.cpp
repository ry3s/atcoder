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
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;

int main() {
    int h, n; cin >> h >> n;
    vector<pair<int, int>> arr(n);
    vector<pair<double, int>> v(n);
    rep(i, n) {
        int a, b; cin >> a >> b;
        arr[i] = { a, b };
    }

    long long dp[n + 1][h + 1];
    rep(i, n + 1) {
        rep(j, h + 1) {
            dp[i][j] = 1e15;
        }
    }
    dp[0][0] = 0;
    rep(i, n) {
        rep(j, h + 1) {
            long long tmp = max(0, j - arr[i].first);
            dp[i + 1][j] = min(dp[i + 1][j],
                               min(dp[i][j], dp[i + 1][tmp] + arr[i].second));
        }
    }

    cout << dp[n][h] << endl;
}
