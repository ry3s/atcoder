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
    int n; uint64_t k; cin >> n >> k;
    vector<int> a(n);
    for (auto &v: a) cin >> v;
    vector<int> f(n);
    for (auto &v: f) cin >> v;

    int64_t sum = 0;
    for (auto &v : a) {
        sum += v;
    }
    int64_t avg = (sum - k + n - 1) / n;
    debug(avg);
    if (avg <= 0) {
        cout << 0 << endl;
        return 0;
    }
    sort(a.begin(), a.end(), greater<>());
    int64_t rest_k = k;
    for (auto &v: a) {
        int64_t diff = v - avg;
        debug(diff);
        if (diff <= 0) diff = v;

        if (diff <= rest_k) {
            v = v - diff;
            rest_k -= diff;

        } else {
            v = v - rest_k;
            rest_k = 0;
            break;
        }


    }
    sort(a.begin(), a.end(), greater<>());
    for(auto v: a){
        debug(v);
    }
    sort(f.begin(), f.end());
    int64_t ans = 0;
    rep(i, n) {
        ans = max(ans, (int64_t)a[i] * f[i]);
    }
    cout << ans << endl;
    return 0;
}
