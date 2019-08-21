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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
using ULL = unsigned long long;

template<typename T>
struct BellmanFord {
    struct Edge {
        int from, to; LL cost;
        Edge() {}
        Edge(int from, int to, LL cost): from(from), to(to), cost(cost) {}
    };

    int n;
    vector<vector<int>> graph;
    vector<int> used, reach;
    BellmanFord(int n): n(n), graph(n), used(n, 0), reach(n, 0) {}

    vector<Edge> edges;
    void add_edge(int from, int to, LL cost) {
        edges.push_back(Edge(from, to, cost));
        graph[from].push_back(to);
    }

    void dfs(int v) {
        if (used[v]) return;

        used[v] = 1;
        for (int u : graph[v]) {
            dfs(u);
        }
    }
    LL build(int from, int to, bool &neg_loop) {
        rep(i, n) {
            fill(used.begin(), used.end(), 0);
            dfs(i);
            reach[i] = used[to];
        }

        vector<LL> dist(n, 1e18);
        dist[from] = 0;

        rep(i, n) {
            bool updated = false;

            for (auto e : edges) {
                if (not reach[e.from]
                    or not reach[e.to]
                    or dist[e.from] == 1e18) continue;

                if (dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to] = dist[e.from] + e.cost;
                    updated = true;
                }
            }

            if (not updated) break;
            if (i == n - 1) {
                neg_loop = true;
                return 1e18;
            }
        }
        neg_loop = false;
        return dist[to];
    }
};
int main() {
    int n, m, p;
    cin >> n >> m >> p;
    BellmanFord<int> graph(n);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph.add_edge(a, b, p - c);
    }

    bool neg_loop;
    int res = graph.build(0, n - 1, neg_loop);
    if (neg_loop) {
        cout << -1 << endl;
        return 0;
    } else {
        cout << max((LL)0, (LL)-res) << endl;
        return 0;
    }
}
