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
using LL = long long;
using ULL = unsigned long long;

int main() {
    int n; cin >> n;
    vector<int> b(n - 1);
    rep(i, n - 1) {
        cin >> b[i];
    }
    vector<int> a(n, 0);
    a[0] = b[0];
    a[n - 1] = b[n - 2];
    for (int i = 1; i < n - 1; i++) {
        a[i] = min(b[i - 1], b[i]);
    }
    LL ans = 0;
    rep(i, n) {
        ans += a[i];
        // debug(a[i]);
    }
    cout << ans << endl;
    return 0;
}
