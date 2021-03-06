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

using Edges = vector<pair<int, LL>>;
using Graph = vector<Edges>;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
const LL INF = (1LL << 60);

void dijkstra(const Graph &g, int s, vector<LL> &dist) {
    min_priority_queue<pair<LL, int>> que;
    dist[s] = 0;
    que.push({0, s});
    while (not que.empty()) {
        auto dv = que.top(); que.pop();
        LL v = dv.second;
        int d = dv.first;

        if (dist[v] < d) continue;

        for (auto e : g[v]) {
            if (dist[e.first] > dist[v] + e.second) {
                dist[e.first] = dist[v] + e.second;
                que.push({ dist[e.first], e.first });
            }
        }
    }
}
LL d[100000 + 1];
int main() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    --s; --t;
    Graph graph_yen(n), graph_snu(n);
    rep(i, m) {
        int u, v; LL a, b;
        cin >> u >> v >> a >> b;
        u--; v--;
        graph_yen[u].push_back(make_pair(v, a));
        graph_yen[v].push_back(make_pair(u, a));
        graph_snu[u].push_back(make_pair(v, b));
        graph_snu[v].push_back(make_pair(u, b));
    }
    vector<LL> dist_yen(n, INF), dist_snu(n, INF);
    dijkstra(graph_yen, s, dist_yen);
    dijkstra(graph_snu, t, dist_snu);

    rep(i, n) {
        d[i] = dist_yen[i] + dist_snu[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        chmin(d[i], d[i + 1]);
    }

    LL maxi = 1e15;
    rep(i, n) d[i] = maxi - d[i];
    rep(i, n) printf("%lld\n", d[i]);
    return 0;
}
