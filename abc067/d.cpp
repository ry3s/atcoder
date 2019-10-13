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
using Edges = vector<pair<int, int>>;
using Graph = vector<Edges>;
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const LL INF = (1LL << 60);
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
    int n; cin >> n;
    Graph g(n);
    rep(i, n - 1) {
        int a, b; cin >> a >> b;
        --a, --b;
        g[a].push_back({b, 1});
        g[b].push_back({a, 1});
    }
    auto dist1 = dijkstra(g, 0);
    auto dist2 = dijkstra(g, n - 1);

    int num1 = dist1[n - 1] / 2 + 1;
    int num2 = dist1[n - 1] / 2;
    loop(i, 1, n - 1) {
        if (dist1[i] <= dist2[i]) ++num1;
        else ++num2;
    }
    if (num1 > num2) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }
}
