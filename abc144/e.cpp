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
bool is_possible(int64_t target, const int64_t k, const vector<int> a, const vector<int> f) {
    const int n = a.size();
    int64_t cost = 0;
    rep(i, n) {
        int64_t need = target / f[i];
        cost += max(0LL, (LL)a[i] - need);
    }
    return cost <= k;

}
int main() {
    int n; uint64_t k; cin >> n >> k;
    vector<int> a(n);
    for (auto &v: a) cin >> v;
    vector<int> f(n);
    for (auto &v: f) cin >> v;

    sort(a.begin(), a.end(), greater<>());
    sort(f.begin(), f.end());

    int64_t left = -1, right = 1e18;
    while (abs(left - right) > 1) {
        int64_t mid = (left + right) / 2;
        if (is_possible(mid, k, a, f)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << endl;
    return 0;
}
