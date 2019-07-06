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

LL dp[10000 + 1][50 + 1][50 + 1]; // i, mausuu, width;
int main() {
    int w;
    cin >> w;
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> screens;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        screens.push_back(make_pair(a, b));
    }

    // current width, num screen, current_screen
    rep(i, w + 1) loop(j, 1, k + 1) loop(l, 1, n + 1) {
        dp[i][j][l] = max(dp[i][j][l], dp[i][j][l - 1]);
        if (i - screens[l - 1].first >= 0) {
            dp[i][j][l] =
                max(dp[i][j][l],
                    dp[i - screens[l - 1].first][j - 1][l - 1] + screens[l - 1].second);
        }
    }

    cout << dp[w][k][n] << endl;

    return 0;
}
