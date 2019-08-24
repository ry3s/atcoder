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
const LL MOD = 1e9 +7;
int main() {
    LL n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    LL res = 0;
    rep(i, n - 1) {
        loop(j, i + 1, n) {
            if (a[i] > a[j]) res++;
        }
    }
    LL cnt = 0;
    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;

            if (a[i] < a[j]) {
                cnt++;
                cnt = cnt % MOD;
            }
        }
    }
    LL ans = (res * (k % MOD)) + ( ((k *(k - 1)) / 2) % MOD) * cnt;
    cout << ans % MOD << endl;
    return 0;
}
