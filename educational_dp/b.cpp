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

const LL INF = 1LL << 60;
vector<LL> h(100000 + 1);
vector<LL> dp(100000 + 1);

int main() {
    int n, k;
    cin >> n >> k;
    rep(i, n) {
        cin >> h[i];
    }
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        LL min_step = INF;
        rep(j, min(k, i)) {
            min_step = min(min_step, dp[i - j - 1] + abs(h[i] - h[i - j - 1]));
        }
        dp[i] = min_step;
    }
    cout << dp[n - 1] << endl;

    return 0;
}
