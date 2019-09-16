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
const int MAX_C = 2100;
const LL MOD = 1e9 + 7;
LL com[MAX_C][MAX_C];

template<typename T>
struct Combination {
    vector<T> fact, rfact, inv;
    const LL MOD = 1e9 + 7;
    Combination(int size) : fact(size + 1), rfact(size + 1), inv(size + 1) {
        fact[0] = fact[1] = 1;
        rfact[0] = rfact[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= size; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            rfact[i] = rfact[i - 1] * inv[i] % MOD;
        }
    }
    LL com(int n, int k) {
        if (n < k) return 0;
        if (n < 0 or k < 0) return 0;
        return fact[n] * (rfact[k] * rfact[n - k] % MOD) % MOD;
    }

};
map<LL, LL> prime_factorize(LL n) {
    map<LL, LL> prime_factors;

    for (LL i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++prime_factors[i];
            n /= i;
        }
    }
    if (n != 1) prime_factors[n] = 1;
    return prime_factors;
}
int main() {
    int n; LL m; cin >> n >> m;

    auto factors = prime_factorize(m);
    Combination<LL> com(210000);

    LL ans = 1;
    for (auto it : factors) {
        ans = (ans * com.com(it.second + n - 1, n - 1)) % MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}
