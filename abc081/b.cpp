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
    else if (n == 0) return m;
    else return gcd(n, m % n);
}
int main() {
    int n; cin >> n;
    vector<LL> a(n);
    rep(i, n) cin >> a[i];
    LL g = a[0];
    for (LL e : a) {
        g = gcd(g, e);
    }
    LL ans = 0;
    if (g % 2 == 0) {
        ans = static_cast<LL>(log2(g));
    }
    cout << ans << endl;
}
