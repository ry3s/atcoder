#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
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
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
using ULL = unsigned long long;
const LL MOD = 1e9 + 7;


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    LL ans = 1;
    LL cnt = 0;
    rep(i, 2 * n) {
        if (s[i] == 'B') {
            if (cnt % 2 == 1) {
                ans = ans * (cnt--) % MOD;
            } else {
                cnt++;
                ans *= cnt <= n;
            }
        } else {
            if (cnt % 2 == 1) {
                cnt++;
                ans *= cnt <= n;
            } else {
                ans = ans * (cnt--) % MOD;
            }
        }
    }
    if (cnt != 0) {
        ans = 0;
    }
    loop(i, 1, n + 1) {
        ans = ans * i % MOD;
    }
    cout << ans << endl;
    return 0;
}
