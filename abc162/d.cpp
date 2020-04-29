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
    string s; cin >> s;

    vector<int> acc_r(n + 1, 0);
    vector<int> acc_g(n + 1, 0);
    vector<int> acc_b(n + 1, 0);

    rep(i, n) {
        if (s[n - 1 - i] == 'R') {
            acc_r[i + 1] = acc_r[i] + 1;
            acc_g[i + 1] = acc_g[i];
            acc_b[i + 1] = acc_b[i];
        } else if (s[n - 1 - i] == 'G') {
            acc_r[i + 1] = acc_r[i];
            acc_g[i + 1] = acc_g[i] + 1;
            acc_b[i + 1] = acc_b[i];
        } else {
            acc_r[i + 1] = acc_r[i];
            acc_g[i + 1] = acc_g[i];
            acc_b[i + 1] = acc_b[i] + 1;
        }
    }

    // rep(i, n + 1) {
    //     cout << acc_r[i] << " " << acc_g[i] << " " << acc_b[i] << endl;
    // }
    int64_t ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (s[i] == s[j]) continue;
            char ch;
            if (s[i] == 'R') {
                if (s[j] == 'G') {
                    ch = 'B';
                } else {
                    ch = 'G';
                }
            } else if (s[i] == 'G') {
                if (s[j] == 'R') {
                    ch = 'B';
                } else {
                    ch = 'R';
                }
            } else {
                if (s[j] == 'R') {
                    ch = 'G';
                } else {
                    ch = 'R';
                }
            }
            if (ch == 'R') {
                ans += acc_r[n - j - 1];
            } else if (ch == 'G') {
                ans += acc_g[n - j - 1];
            } else {
                ans += acc_b[n - j - 1];
            }
            if (2 * j - i < n && s[2 * j - i] == ch) {
                ans--;
            }
        }
    }
    cout << ans << endl;

}
