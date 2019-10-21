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
const LL mod = 1e9 + 7;

int main() {
    int n, m; cin >> n >> m;
    if (abs(n - m) > 1) {
        cout << 0 << endl;
        return 0;
    }
    LL ans = 1;
    loop(i, 1, n + 1) {
        ans = ans * i % mod;
    }
    loop(i, 1, m + 1) {
        ans = ans * i % mod;
    }
    cout << ans * ((n == m) + 1) % mod << endl;
}
