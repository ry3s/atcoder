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
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    rep(i, n) {
        int a, b; cin >> a >> b;
        b++;
        arr[i] = { a, b };
    }

    vector<int64_t> imos(1'000'000 + 2, 0);

    for (auto lr: arr) {
        imos[lr.first]++;
        imos[lr.second]--;
    }

    vector<int64_t> acc(1'000'000 + 2, 0);
    rep(i, 1'000'000 + 1) {
        acc[i + 1] = acc[i] + imos[i];
    }

    int64_t ans = 0;
    for (auto x: acc) {
        ans = max(ans, x);
    }
    cout << ans << endl;
}
