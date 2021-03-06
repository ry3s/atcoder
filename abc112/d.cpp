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

vector<LL> make_divisors(LL n) {
    vector<LL> res;

    for (LL i = 1LL; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }

    return res;
}
int main() {
    int n; LL m;
    cin >> n >> m;

    auto divs = make_divisors(m);

    LL ans = 1;
    for (auto d : divs) {
        if (d * n <= m) ans = max(ans, d);
    }
    cout << ans << endl;
}
