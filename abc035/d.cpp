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

using Edges = vector<pair<int, int>>;
using Graph = vector<Edges>;
const LL INF = (1LL << 60);

vector<LL> dijkstra(const Graph &g, int n, int s) {
    vector<LL> dist(n, INF);
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> que;
    dist[s] = 0;
    que.push({0, s});
    while (not que.empty()) {
        auto dv = que.top(); que.pop();
        LL d = dv.first;
        int v = dv.second;

        if (dist[v] < d) continue;
        for (auto e : g[v]) {
            if (dist[e.first] > dist[v] + e.second) {
                dist[e.first] = dist[v] + e.second;
                que.push({ dist[e.first], e.first });
            }
        }
    }
    return dist;
}
int main() {
    int n, m; LL t; cin >> n >> m >> t;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    Graph graph_go(n), graph_back(n);
    rep(i, m) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        graph_go[a].push_back(make_pair(b, c));
        graph_back[b].push_back(make_pair(a, c));
    }

    auto dist_go = dijkstra(graph_go, n, 0);
    auto dist_back = dijkstra(graph_back, n, 0);

    LL ans = 0;
    rep(i, n) {
        if (dist_go[i] + dist_back[i] <= t) {
            LL value = (t - dist_go[i] - dist_back[i]) * a[i];
            ans = max(ans, value);
        }
    }
    cout << ans << endl;
    return 0;
}
