#include <cstdio>
#include <climits>
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
#include <numeric>
#include <bitset>
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
unsigned gcd(unsigned a, unsigned b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a < b) gcd(b, a);
    unsigned r;
    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n;
    cin >> n;
    vector<LL> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<LL> l_gcd(n, 0), r_gcd(n, 0);

    l_gcd[0] = a[0];
    for (LL i = 1; i < n; i++) {
        l_gcd[i] = gcd(l_gcd[i - 1], a[i]);
    }

    r_gcd[n - 1] = a[n - 1];
    for (LL i = n - 2; i >= 0; i--) {
        r_gcd[i] = gcd(r_gcd[i + 1], a[i]);
    }

    LL ans = r_gcd[1];
    for (LL i = 1; i < n - 1; i++) {
        ans = max(ans, (LL)gcd(l_gcd[i - 1], r_gcd[i + 1]));
    }
    ans = max(ans, l_gcd[n - 2]);
    cout << ans << endl;
}
