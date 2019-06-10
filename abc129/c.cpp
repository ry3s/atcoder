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
LL dp[101010];
const LL MOD =  1000000007;
int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> v(n + 1, true);
    rep(i, m) {
        int x;
        cin >> x ;
        v[x] = false;
    }

    dp[0] = 1;
    if (v[1] == true) {
        dp[1] = 1;
    } else {
        dp[1] = 0;
    }

    for (int i = 2; i <= n; i++) {
        if (v[i] == false) {
            dp[i] = 0;
            continue;
        }
        LL dist1 = 0, dist2 = 0;
        if (v[i - 1] == false) {
            dist1 = 0;
        } else {
            dist1 = dp[i - 1];
        }
        if (v[i - 2] == false) {
            dist2 = 0;
        } else {
            dist2 = dp[i - 2];
        }
        dp[i] = dist1 % MOD + dist2 % MOD;
    }
    cout << dp[n] % MOD << endl;
    return 0;
}
