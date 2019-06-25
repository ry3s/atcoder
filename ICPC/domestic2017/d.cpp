#include <cstdio>
#include <climits>
#include <cassert>
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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
using LL = long long int;
using ULL = unsigned long long int;
vector<string> b(500);
vector<bool> e(514);
// (i : recipe, bit : rest of ingredients)
vector<vector<int>> dp(2, vector<int>(1<<24));
ULL string_to_binary(string s) {
    ULL ret = 0;
    ULL digit = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        ret += (s[i] - '0') * digit;
        digit *= 2;
    }
    return ret;
}

void exhaustive_search(int n, int m) {
    // input
    rep(i, n) {
        cin >> b[i];
    }
    // 全探索
    int ans = 0;;
    for (int bit = 1; bit < (1 << n); bit++) {
        int cnt = 0;
        rep(i, n) {
            if (bit & (1 << i)) {
                cnt++;
                rep(k, m) {
                    if (b[i][k] == '1')
                        e[k] = not e[k];
                }
            }
        }
        bool ok = false;
        rep(i, m) {
            if (e[i]) ok = false;
        }
        if (ok) {
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}
void dynamic_programming(int n, int m) {
    // input
    rep(i, n) {
        cin >> b[i];
    }
    vector<ULL> v(n);
    rep(i, n) {
        v[i] = string_to_binary(b[i]);
    }
    fill(dp.begin(), dp.end(), -1);


    dp[0][0] = 0;
    int k = 1;
    for (int i = 0; i < n; i++) {
        rep(j, 1 << m) {
            dp[k][j] = dp[not k][j];
        }
        for (int j = 0; j < (1 << m); j++) {
            int x = j ^ v[i];
            if (dp[not k][j] >= 0) {
                dp[k][x] = max(dp[k][x], dp[not k][j] + 1);
            }
        }
        k = not k;
    }
    cout << dp[not k][0] << endl;
}
int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 and m == 0) {
            break;
        } else if (n < m) {
            exhaustive_search(n, m);
        } else { // m > n
            dynamic_programming(n, m);
        }

    }

}
