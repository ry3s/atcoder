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
const long long mod = 1e9 + 7;
map<long long, int>
prime_factor(long long n) {
    map<long long, int> ret;

    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }

    if (n != 1) ret[n] = 1;
    return ret;
}

long long
mod_pow(long long a, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

long long
mod_inv(long long a) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

int
main() {
    int n; cin >> n;

    vector<long long> arr(n);
    vector<map<long long, int>> vec;
    vector<long long> count(1000000);
    rep(i, n) {
        cin >> arr[i];
        vec.push_back(prime_factor(arr[i]));
    }

    for (auto mp: vec) {
        for (auto pn: mp) {
            count[pn.first] = max(count[pn.first], (long long)pn.second);
        }
    }

    long long l = 1;
    for (int i= 2; i <= 1000000; i++) {
        if (count[i]) {
            l *= mod_pow(i, count[i]);
            l %= mod;
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (l * mod_inv(arr[i])) % mod;
        ans %= mod;
    }

    ans %= mod;
    cout << ans << endl;
}
