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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
void solve(int n, int m) {
    vector<LL> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    LL ans = 0;
    rep(i, n - 1) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] <= m) {
                ans = max(ans, a[i] + a[j]);
            }
        }
    }

    if (ans == 0) {
        cout << "NONE" << endl;
    } else {
        cout << ans << endl;
    }
}
int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 and m == 0) break;
        solve(n, m);
    }
    return 0;
}
