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

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    vector<LL> h(n);
    rep(i, n) {
        cin >> h[i];
    }
    vector<LL> dp(n);
    rep(i, n) {
        dp[i] = INF;
    }

    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i > 1) {
            chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}
