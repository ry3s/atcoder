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
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int64_t>> dist(n, vector<int64_t>(n, 1e9));
    rep(i, n) rep(j, n) if (i == j) dist[i][j] = 0;
    rep(i, m) {
        int u, v, l; cin >> u >> v >> l;
        u--, v--;
        dist[u][v] = l;
        dist[v][u] = l;
    }
    for (LL k = 1; k < n; k++) for (LL i = 1; i < n; i++) for(LL j = 1;j < n;j ++){
        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
    }
    int64_t ans = 1e9;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto k = dist[0][i] + dist[i][j] + dist[j][0];
            if (k > 1e9) continue;
            else ans = min(ans, k);
        }
    }

    if (ans < 1e9) {
        cout << ans << endl;
    } else  {
        cout << -1 << endl;
    }
}
