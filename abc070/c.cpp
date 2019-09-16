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
#include <numeric>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
using ULL = unsigned long long;

ULL gcd(ULL m, ULL n) {
    if (n > m) return gcd(n, m);
    if (n == 0) return m;
    return gcd(n, m % n);
}
ULL lcm(ULL m, ULL n) {
    return m / gcd(m, n) * n;
}
int main() {
    int n; cin >> n;
    vector<ULL> t(n);
    rep(i, n) {
        cin >> t[i];
    }
    ULL ans = accumulate(t.begin(), t.end(), t[0], lcm);
    cout << ans << endl;
}
