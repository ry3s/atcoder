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

int main() {
    int n;
    cin >> n;
    vector<LL> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vector<LL> ans(n, 0);

    ans[0] = a[0];
    for (int j = 1; j < n; j++) {
        if (j % 2 == 0) {
            // plus
            ans[0] += a[(0 + j) % n];
        } else {
            // minus
            ans[0] -= a[(0 + j) % n];
        }
    }
    a[0] -= ans[0] / 2;
    for (int i = 1; i < n; i++) {
        ans[i] = 2 * (a[i - 1]);
        a[i] -= ans[i] / 2;
    }
    rep(i, n) {
        if (i == n - 1) {
            cout << ans[i] << endl;
        } else {
            cout << ans[i] << " ";
        }
    }
    return 0;
}
