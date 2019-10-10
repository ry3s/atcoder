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

using Edges = vector<int>;
using Graph = vector<Edges>;
vector<bool> visited;
bool dfs(int cur, int par, int dist, const Graph &g) {
    int n = g.size();
    visited[cur] = true;
    if (cur == n - 1) return dist == 2;

    bool res = false;
    for (auto next: g[cur]) if (next != par and not visited[next]){
            res = res or dfs(next, cur, dist + 1, g);
    }
    return res;
}
int main() {
    int n, m; cin >> n >> m;
    Graph graph(n);
    rep(i, m) {
        int a, b; cin >> a >> b;
        --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    visited.assign(false, n);
    if (dfs(0, -1, 0, graph)) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
