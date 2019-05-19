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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

using Edge = pair<LL, LL>;
using Graph = vector<vector<Edge> >;

int n;
Graph graph;
vector<int> res;

void dfs(int v, int parent, int color) {
    res[v] = color;
    for (auto e : graph[v]) {
        if (e.first == parent) continue;
        if (e.second % 2 != 0) dfs(e.first, v, 1 - color);
        else dfs(e.first, v, color);
    }
}
int main() {
    cin >> n;
    graph.assign(n, vector<Edge>());

    rep(i, n - 1) {
        LL u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back(Edge(v, w));
        graph[v].push_back(Edge(u, w));
    }
    res.assign(n, 0);
    dfs(0, -1, 1);
    for (auto i: res) {
        cout << i << endl;
    }
}
