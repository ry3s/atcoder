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

int main() {
    int n; cin >> n;
    vector<LL> a(n);
    rep(i, n) cin >> a[i];

    vector<LL> acc_left(n + 1, 0), acc_right(n + 1, 0);
    rep(i, n) {
        acc_left[i + 1] = a[i] + acc_left[i];
    }
    rep(i, n) {
        acc_right[i + 1] = acc_right[i] + a[n - 1 - i];
    }

    LL ans = 1LL << 60;
    loop(i, 1, n) {
        ans = min(ans, abs(acc_left[i] - acc_right[n - i]));
    }
    cout << ans << endl;
}
