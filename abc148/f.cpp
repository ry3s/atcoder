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
using Graph = vector<vector<int>>;
Graph g;
int dist[101010][2];

void dfs(int cur, int pre, int d, int id) {
    dist[cur][id] = d;

    for (const auto next: g[cur]) {
        if (next != pre) {
            dfs(next, cur, d + 1, id);
        }
    }
}
int main() {
    int n, u, v; cin >> n >> u >> v;
    u -= 1;
    v -= 1;
    g.assign(n, vector<int>());
    rep(i, n - 1) {
        int a, b; cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(u, u, 0, 0);
    dfs(v, v, 0, 1);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i][0] < dist[i][1]) {
            ans = max(ans, dist[i][1] - 1);
        }
    }
    cout << ans << endl;
}
