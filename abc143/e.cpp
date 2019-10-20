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

const LL INF = (1LL << 60);
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
using Edge = pair<int, LL>;
using Edges = vector<Edge>;
using Graph = vector<Edges>;
vector<LL> dijkstra(const Graph &g, int s) {
    int n = g.size();
    vector<LL> dist(n, INF);
    min_priority_queue<pair<LL, int>> que;

    que.push({0, s});
    dist[s] = 0;
    while(not que.empty()) {
        auto dv = que.top(); que.pop();
        LL d = dv.first;
        int v = dv.second;

        if (dist[v] < d) continue;
        for (auto e : g[v]) {
            if (dist[v] + e.second < dist[e.first]) {
                dist[e.first] = dist[v] + e.second;
                que.push({dist[e.first], e.first});
            }
        }
    }
    return dist;
}

int main() {
    long long n, m, l; cin >> n >> m >> l;
    Graph g(n);
    rep(i, m) {
        LL a, b, c; cin >> a >> b >> c;
        --a, --b;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    auto dist = dijkstra(g, 0);
    int q; cin >> q;
    rep(i, q) {
        int s, t; cin >> s >> t;
        --s, --t;
        LL dist = mat[s][t];
        if (dist == INF) {
            cout << -1 << endl;
        } else {
            cout << << endl;
        }
    }
}
