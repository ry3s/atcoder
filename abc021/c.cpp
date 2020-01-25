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
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;

const int64_t mod = 1e9 + 7;

using Edges = vector<int>;
using Graph = vector<Edges>;

vector<int64_t>
bfs(int start, int goal, Graph g) {
    int n = g.size();
    vector<int64_t> count(n, 0);
    vector<int> dist(n, -1);
    queue<int> que;

    count[start] = 1;
    dist[start] = 0;
    que.push(start);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();


        if (cur == goal) break;
        for (int next: g[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                count[next] = (count[next] + count[cur]) % mod;
                que.push(next);
            } else if (dist[next] == dist[cur] + 1) {
                count[next] = (count[next] + count[cur]) % mod;
            }
        }
    }
    return count;
}
int main() {
    int n; cin >> n;
    int a, b; cin >> a >> b; --a, --b;

    Graph graph(n);
    int m; cin >> m;
    rep(i, m) {
        int x, y; cin >> x >> y;
        --x, --y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cout << (bfs(a, b, graph))[b] << endl;
}
