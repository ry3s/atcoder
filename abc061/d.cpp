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
struct BellmanFord {
    struct Edge {
        int from, to; LL cost;
        Edge() {}
        Edge(int from, int to, LL cost): from(from), to(to), cost(cost) {}
    };
    const LL INF = (1LL << 60);
    int n;
    vector<vector<int>> graph;
    vector<int> used, reach;
    vector<LL> dist;
    BellmanFord(int n): n(n), graph(n), used(n, 0), reach(n, 0), dist(n, INF) {}

    vector<Edge> edges;
    void add_edge(int from, int to, LL cost) {
        edges.push_back(Edge(from, to, cost));
        graph[from].push_back(to);
    }
    bool bfs(int s, int pre) {
        if (s == n - 1) return true;

        for (auto e : graph[s]) {
            if (e != pre and bfs(e, s)) return true;
        }
        return false;
    }
    void build(int s, bool &neg_loop) {
        neg_loop = false;
        dist[s] = 0;
        rep(i, n * 2) {
            for (auto e : edges) {
                if (dist[e.from] != INF and dist[e.from] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[e.from] + e.cost;

                    if (i >= n - 1 and e.to == n - 1) {
                        neg_loop = true;

                    }
                }
            }
        }
    }
};
int main() {
    int n, m; cin >> n >> m;
    BellmanFord bf(n);
    rep(i, m) {
        int a, b; LL c; cin >> a >> b >> c;
        --a; --b;
        bf.add_edge(a, b, -c);
        // bf.add_edge(b, a, -c);
    }

    bool neg_loop;
    bf.build(0, neg_loop);
    if (neg_loop) {
        cout << "inf" << endl;
    } else {
        cout << -bf.dist[n - 1] << endl;
    }
    return 0;
}
