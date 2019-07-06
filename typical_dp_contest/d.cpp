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

double dp[2][100][50][50]; // i, 2, 3, 5

int main() {
    LL n, d;
    cin >> n >> d;
    LL c2 = 0, c3 = 0, c5 = 0;
    while (d % 2 == 0) {
        d /= 2;
        c2++;
    }
    while (d % 3 == 0) {
        d /= 3;
        c3++;
    }
    while (d % 5 == 0) {
        d /= 5;
        c5++;
    }
    if (d != 1) {
        printf("%.10f\n", 0.0);
        return 0;
    }

    dp[0][0][0][0] = 1;

    rep(i, n) {
        rep(i2, c2 + 1) rep(i3, c3 + 1) rep(i5, c5 + 1) {
            for (int  j = 1; j <= 6; j++) {
                int nc2 = min(c2, (j == 2 || j == 6 ? i2 + 1 : (j == 4 ? i2 + 2 : i2)));
                int nc3 = min(c3, (j % 3 == 0 ? i3 + 1 : i3));
                int nc5 = min(c5, (j % 5 == 0 ? i5 + 1 : i5));
                dp[(i + 1) & 1][nc2][nc3][nc5] +=
                    dp[i & 1][i2][i3][i5] / 6.0;
            }
            dp[i & 1][i2][i3][i5] = 0;
        }
    }
    printf("%.10lf\n",dp[n & 1][c2][c3][c5]);
    return 0;
}
