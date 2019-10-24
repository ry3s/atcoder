a#include <cstdio>
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

int64_t solve(const vector<int64_t> &a, int64_t init) {
    const int n = a.size();
    int64_t cnt = abs(init);
    int64_t acc = a[0] + init;

    rep(i, n - 1) {
        int64_t next = acc + a[i + 1];

        if (acc > 0 and next >= 0) {
            cnt += next + 1;
            next = -1;
        }
        if (acc < 0 and next <= 0) {
            cnt += -next + 1;
            next = 1;
        }
        acc = next;
    }
    return cnt;
}
int main() {
    int n; cin >> n;
    vector<int64_t> a(n);
    for (auto &e: a) { cin >> e; };

    int64_t ans = min({solve(a, 0),
                       solve(a, -a[0] - 1),
                       solve(a, -a[0] + 1)});
    cout << ans << endl;
}
