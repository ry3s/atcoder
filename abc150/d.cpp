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

long long gcd(long long a, long long b) {
    if (a < b) return gcd(b, a);

    int r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
    int n, m; cin >> n >> m;
    vector<long long> as(n);
    rep(i, n) cin >> as[i];

    for (auto& a: as) {
        a = a / 2;
    }

    long long res = 1;
    for (const auto& a: as) {
        res = lcm(res, a);
    }

    for (const auto& a: as) {
        if (res / a % 2 == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << (m / res + 1) / 2 << endl;
}
