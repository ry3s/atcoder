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

long long dp[51][51][50 * 50 + 1]; // dp[index][num of cards][sum] = 総数

int main() {
    int n, a; cin >> n >> a;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int sum = 0; sum < 50 * 50 + 1; sum++) {
                if (sum + x[i] < 50 * 50 + 1) {
                    dp[i + 1][j + 1][sum + x[i]] += dp[i][j][sum];
                }

                dp[i + 1][j][sum] += dp[i][j][sum];
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int sum = 1; sum <= 50 * 50 + 1; sum++) {
            if (sum == a * i) {
                ans += dp[n][i][sum];
            }
        }
    }

    cout << ans << endl;
}
