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

LL gcd(LL m, LL n) {
    if (m < n) return gcd(n, m);
    if (n == 0) return m;
    else return gcd(n, m % n);

}
LL prime_factorize(long long n) {
    LL res = 0;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        while (n % p == 0) n /= p;
        res++;
    }
    if (n != 1) res++;
    return res;
}

int main() {
    ULL a, b; cin >> a >> b;
    ULL g = gcd(a, b);
    auto ans = prime_factorize(g);
    cout << ans + 1 << endl;;
}
