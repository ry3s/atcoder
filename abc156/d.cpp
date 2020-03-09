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

const int64_t mod = 1e9 + 7;

struct Combination {
    vector<int64_t> fac, finv, inv;
    const int64_t MOD = 1e9 + 7;
    Combination(int size)
        : fac(size + 1), finv(size + 1), inv(size + 1) {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < size + 1; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    int64_t com(int n, int k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }

    int64_t modpow(int64_t a, int64_t n) {
        int64_t res = 1;
        while (n > 0) {
            if (n & 1) res = res * a % MOD;
            a = a * a % MOD;
            n >>= 1;
        }
        return res;
    }
};

int main() {
    int64_t n, a, b; cin >> n >> a >> b;

    Combination cm(510000);

    int64_t v1 = 1;
    for (int64_t i = n; i > n - a; i--) {
        v1 *= i;
        v1 %= mod;
    }
    int64_t v2 = 1;
    for (int64_t i = n; i > n - b; i--) {
        v2 *= i;
        v2 %= mod;
    }

    v1 *= cm.finv[a];
    v2 *= cm.finv[b];
    v1 %= mod;
    v2 %= mod;
    int64_t ans = cm.modpow(2, n) - 1 - v1 - v2;
    ans += 10 * mod;
    ans %= mod;
    cout << ans % mod << endl;
}
