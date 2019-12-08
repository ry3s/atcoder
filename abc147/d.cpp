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
const long long MOD = 1e9 + 7;
long long dp[3 * 100000 + 1];

int main() {
    long long n; cin >> n;
    vector<long long> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    long long ans = 0;

    for (int i = 0; i <  - 1; i++) {
        for (int i = 1; i < n; i++) {                ans = (ans + (a[i] ^ a[0]));
    }


    }
    cout << ans  % MOD << endl;
}
