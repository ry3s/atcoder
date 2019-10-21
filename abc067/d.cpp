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
Graph graph;
vector<vector<int>> dist;
int id;

void dfs(int s, int par) {
    if (~par) dist[id][s] = dist[id][par] + 1;
    for (auto &next: graph[s]) {
        if (next != par) dfs(next, s);
    }

}

int main() {
    int n; cin >> n;
    graph.assign(n, Edges());
    dist.assign(2, vector<int>(n, 1e9));
    rep(i, n - 1) {
        int a, b; cin >> a >> b;
        --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    id = 0;
    dfs(0, -1);
    id = 1;
    dfs(n - 1, -1);

    int ans = 0;
    rep(i, n) {
        if (dist[0][i] <= dist[1][i]) ++ans;
    }
    if (ans >= (n + 2) / 2) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}
