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
int main() {
    long long n; cin >> n;
    vector<long long> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    long long res = 0;
    for (int d = 0; d < 60; d++) {
        long long n0 = 0, n1 = 0;

        for (int i = 0; i < n; i++) {
            if ((a[i] >> d) & 1) ++n1;
            else ++n0;
        }

        long long tmp = (1LL << d) % MOD; // 2 ** d
        long long x = n0 * n1 % MOD;

        tmp = tmp * x % MOD;
        res = (res + tmp) % MOD;
    }
    cout << res << endl;
}
