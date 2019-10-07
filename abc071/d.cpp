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

const LL MOD = 1000000007;

int main() {
    int n; cin >> n;
    vector<string> ss(2);
    cin >> ss[0] >> ss[1];

    LL ans = 1;
    int x = 0;
    int pre = -1;

    while (x < n) {
        if (ss[0][x] == ss[1][x]) {
            if (pre == -1) ans = 3;
            else if (pre == 0) ans *=2, ans = ans % MOD;
            ++x; pre = 0;
        } else {
            if (pre == -1) ans = 6;
            else if (pre == 0) ans *= 2, ans = ans % MOD;
            else ans *= 3, ans = ans % MOD;
            x += 2; pre = 1;
        }
    }
    cout << ans % MOD << endl;
}
