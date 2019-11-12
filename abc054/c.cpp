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

int cnt = 0;

void dfs(int cur, int par, Graph const &graph, vector<bool> visited) {
    visited[cur] = true;
    if (all_of(visited.begin(), visited.end(), [](auto x) { return x; })) {
        cnt++;
        return;
    }

    for (auto next: graph[cur]) {
        if (!visited[next] && next != par) {
            dfs(next, cur, graph, visited);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    Graph graph(n);

    rep(i, m) {
        int a, b; cin >> a >> b, --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cnt = 0;
    vector<bool> visited(n, false);
    dfs(0, -1, graph, visited);
    cout << cnt << endl;
}
