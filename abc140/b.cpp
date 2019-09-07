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
    vector<int> a(n), b(n), c(n - 1);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        cin >> b[i];
    }
    rep(i, n - 1) {
        cin >> c[i];
    }
    LL ans = 0;
    rep(i, n) {
        ans += b[a[i] - 1];
        if (i != n - 1) {
            if (a[i + 1] == a[i] + 1) ans += c[a[i] - 1];
        }

    }
    cout << ans << endl;
    return 0;
}
