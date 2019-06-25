#include <cstdio>
#include <climits>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <array>
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

// (i : recipe, bit : rest of ingredients)
int dp[2][1 << 24];

int string_to_binary(string s) {
    int ret = 0;
    int digit = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        ret += (s[i] - '0') * digit;
        digit *= 2;
    }
    return ret;
}
int count_bits(int bits){
    int num;

    num = (bits >> 1) & 03333333333;
    num = bits - num - ((num >> 1) & 03333333333);
    num = ((num + (num >> 3)) & 0707070707) % 077;

    return num;
}
void exhaustive_search(int n, int m) {
    // input
    vector<string> b(n);
    rep(i, n) {
        cin >> b[i];
    }
    vector<bitset<512>> vb(n);
    rep(i, n) {
        rep(j, m) {
            if (b[i][j] == '1') {
                vb[i][j] = 1;
            }
        }
    }
    // exhaustive search
    int ans = 0;
    rep(bits, 1 << n) {
        int k = count_bits(bits);
        if (ans >= k) continue;

        bitset<512> sum;
        rep(i, n) {
            if (bits & (1 << i)) {
                sum ^= vb[i];
            }
        }

        if (sum.none()) {
            ans = max(ans, k);
        }
    }
    cout << ans << endl;
}
void dynamic_programming(int n, int m) {
    // input
    vector<string> b(n);
    rep(i, n) {
        cin >> b[i];
    }
    vector<int> v(n);
    rep(i, n) {
        v[i] = string_to_binary(b[i]);
    }
    rep(i, 2) rep(j, 1 << 24) {
        dp[i][j] = -1;
    }

    dp[0][0] = 0;
    int current = 0;
    int next = 1;
    rep(i, n) {
        rep(j, 1 << m) {
            dp[next][j] = dp[current][j];
        }
        rep(bit, 1 << m) {
            if (dp[current][bit] >= 0) {
                dp[next][bit ^ v[i]] = max(dp[next][bit ^ v[i]], (short)dp[current][bit] + 1);
            }
        }
        swap(current, next);
    }
    cout << dp[current][0] << endl;
}
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 and m == 0) {
            break;
        } else if (m > 20) {
            exhaustive_search(n, m);
        } else { // m > n
            dynamic_programming(n, m);
        }

    }
    return 0;

}
