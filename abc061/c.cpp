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
    int n; LL k; cin >> n >> k;

    vector<pair<LL, LL>> cnt(n);
    rep(i, n) cin >> cnt[i].first >> cnt[i].second;

    sort(cnt.begin(), cnt.end());

    LL ans = 0;
    LL sum = 0;
    for (auto &p: cnt) {
        sum += p.second;
        if (sum >= k) {
            ans = p.first;
            break;
        }
    }
    cout << ans << endl;
}
