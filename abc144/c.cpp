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

vector<pair<int64_t, int64_t>>
make_divisors(int64_t n) {
    vector<pair<int64_t, int64_t>> ret;
    for (int64_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back({i, n / i});
        }
    }
    return ret;
}
int main() {
    int64_t n; cin >> n;

    auto divs = make_divisors(n);
    int64_t ans = (1LL << 60);
    for (auto &p: divs) {
        auto x = p.first;
        auto y = p.second;
        auto diff = abs(x - 1) + abs(y - 1);
        ans = min(ans, diff);
    }
    cout << ans << endl;
    return 0;
}
