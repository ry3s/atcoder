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
    int n; cin >> n;
    vector<int> t(n), v(n);
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> v[i];

    const int max_v = *max_element(v.begin(), v.end());
    constexpr int zoom = 2;

    vector<double> cur(zoom * max_v + 3, - INFINITY);
    vector<double> pre(zoom * max_v + 3, - INFINITY);

    cur[0] = 0;
    rep(i, n) {
        fill(cur.begin() + (zoom * v[i] + 1), cur.end(), - INFINITY);
        fill(pre.begin() + (zoom * v[i] + 1), pre.end(), - INFINITY);

        rep(tick, zoom * t[i]) {
            cur.swap(pre);
            cur[0] = max(pre[0], pre[1] + 0.5 / zoom);

            loop(a, 1, zoom * v[i] + 1) {
                cur[a] =
                    max({ pre[a - 1] - 0.5 / zoom,
                          pre[a],
                          pre[a + 1] + 0.5 / zoom })
                    + a / (double)(zoom * zoom);
            }
        }
    }
    printf("%.12lf\n", cur[0]);
    return 0;
}
