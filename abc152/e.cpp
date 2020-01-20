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
long long gcd(long long a, long long b) {
    if (a < b) return gcd(b, a);

    long long r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

vector<long long> make_divisors(long long n) {
    vector<long long> res;

    for (long long i = 1LL; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }

    sort(res.begin(), res.end());
    return res;
}
int main() {
    int n; cin >> n;
    vector<long long> arr(n);
    rep(i, n) cin >> arr[i];

    long long lcms = 1;
    auto x = arr[0];
    bool is_same = true;
    for (auto a: arr) {
        lcms = lcm(lcms, a);
        if (x != a) is_same = false;
    }
    auto divs = make_divisors(lcms);
    sort(divs.begin(), divs.end());
    if (is_same) {
        cout << n << endl;
    } else {
        for (auto d: divs) {
            bool ok = true;
            for (auto a: arr) {
                if (d % a != 0) ok = false;
            }
            if (ok) {
                long long ans = 0;
                for (auto a: arr) {
                    ans = (ans + lcms / a) % MOD;
                }
                cout << ans % MOD << endl;
                return 0;
            }
        }
    }
}
