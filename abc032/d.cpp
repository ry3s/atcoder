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
long long dp[201][200000];
long long n, w;
vector<pair<long long, long long>> items;
const long long MAXI = 1000 * 200;
void solve1() {
    // dp[i][weight] = total value

    rep(i, w + 1) {
        dp[0][i] = 0;
    }

    rep(i, n) {
        const auto value = items[i].first;
        const auto weight = items[i].second;

        rep(nw, w + 1) {
            if (nw >= weight) {
                dp[i + 1][nw] = max(dp[i][nw - weight] + value,
                                    dp[i][nw]);
            } else {
                dp[i + 1][nw] = dp[i][nw];
            }
        }
    }

    long long ans = 0;
    rep(i, w + 1) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
}
void solve2() {
    // dp[i][value]
    rep(i, n) {
        rep(j, MAXI) {
            dp[i][j] = (1LL << 60);
        }
    }

    dp[0][0] = 0;
    rep(i, n) {
        const auto value = items[i].first;
        const auto weight = items[i].second;

        rep(nv, MAXI) {
            if (nv - value < 0) {
                dp[i + 1][nv] = dp[i][nv];
            } else {
                dp[i + 1][nv] = min(dp[i][nv], dp[i][nv - value] + weight);
            }
        }
    }

    long long ans = 0;
    rep(i, MAXI) {
        if (dp[n][i] <= w) ans = i;
    }
    cout << ans << endl;
}

void solve3() {
    vector<pair<long long, long long>> va, vb;
    for (int i = 0; i < n / 2; i++) va.push_back(items[i]);
    for (int i = n / 2; i < n; i++) vb.push_back(items[i]);

    vector<pair<long long, long long>> a_list;
    int vasize = va.size();
    for (int bit = 0; bit < (1 << vasize); bit++) {
        long long value_sum = 0;
        long long weight_sum = 0;
        rep(i, vasize) {
            if (bit & (1 << i)) {
                value_sum += va[i].first;
                weight_sum += va[i].second;
            }
        }

        a_list.push_back({ weight_sum, value_sum });

    }
    sort(a_list.begin(), a_list.end());
    int m = 1;
    for (int i = 1; i < (int)a_list.size(); i++) {
        if (a_list[m - 1].second < a_list[i].second) {
            a_list[m++] = a_list[i];
        }
    }
    int vbsize = vb.size();
    long long ans = 0;
    for (int bit = 0; bit < (1 << vbsize); bit++) {
        long long value_sum = 0;
        long long weight_sum = 0;
        rep(i, vbsize) {
            if (bit & (1 << i)) {
                value_sum += vb[i].first;
                weight_sum += vb[i].second;
            }
        }
        if (weight_sum <= w) {
            long long tmp_value =
                (lower_bound(a_list.begin(), a_list.begin() + m,
                             make_pair(w - weight_sum, (1LL << 60)))
                 - 1)->second;
            ans = max(ans, value_sum + tmp_value);
        }
    }
    cout << ans << endl;
}
int main() {
    cin >> n >> w;

    items.assign(n, pair<long long, long long>());
    bool flag = false;
    rep(i, n) {
        long long v, w;
        cin >> v >> w;
        if (v > 1000) flag = true;
        items[i] = { v, w };
    }

    if (n <= 30) {
        solve3();
    } else if (flag) {
        solve1();
    } else {
        solve2();
    }

}
