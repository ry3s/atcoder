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

const LL  MAX = 2000001;
const LL  MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (long long  i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(long long  n, long long k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {
    long long x, y; cin >> x >> y;
    COMinit();

    // if ((x + y) % 3 !=0) {
    //     cout << 0 << endl;
    //     return 0;
    // }
    long long ans = 0;
    for (long long i = 1; i <= 1e6; i++) {
        long long a = i;
        long long b = x - 2 * a;
        if (a >= 0 && b >= 0 &&
            2 * a + b == x
            && a + 2 * b == y) {
            if (b < a) {
                ans = (ans + COM(a + b, b)) % MOD;
            } else {
                ans = (ans + COM(a + b, a)) % MOD;
            }

        }
    }
    cout << ans << endl;
}
