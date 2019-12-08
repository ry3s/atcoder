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

template <typename T>
struct Combination {
    vector<T> fac, finv, inv;
    const LL MOD = 1e9 + 7;
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
    long long com(int n, int k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
};
int main() {
    int h, w, a, b; cin >> h >> w >> a >> b;

    Combination<long long> com(h + w);

    long long ans = 0;
    for (int i = b; i < w; i++) {
        ans += com.com(h + i - a - 1, i)
            * com.com(w - 1 - i + a - 1, a - 1) % MOD;

    }
    cout << ans % MOD<< endl;
}
