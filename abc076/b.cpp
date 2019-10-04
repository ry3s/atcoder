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
    int n, k; cin >> n >> k;
    LL ans = 1e9;
    rep(bit, 1 << n) {
        LL cnt = 1;
        rep(i, n) {
            if (bit & (1 << i)) {
                cnt *= 2;
            } else {
                cnt += k;
            }
        }
        ans = min(ans , cnt);
    }
    cout << ans << endl;
}
