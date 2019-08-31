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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;
int gcd(int m, int n) {
    if (n > m) return gcd(n, m);

    if (n == 0) return m;
    else return gcd(n, m % n);
}
int main() {
    int n; cin >> n;
    vector<LL> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int res = a[0];
    for (auto x : a) {
        res = gcd(res, x);
    }
    cout << res << endl;
}
