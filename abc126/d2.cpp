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

Graph graph;
vector<int> colors;

void dfs(int v, int par, int color) {
    colors[v] = color;

    for (auto e : graph[v]) {
        if (e.first == par) continue;
        if (e.second % 2 != 0) dfs(e.first, v, 1 - color);
        else dfs(e.first, v, color);
    }
}
int main() {
    int n; cin >> n;
    graph.assign(n, Edges());
    rep(i, n - 1) {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        --u; --v;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    colors.assign(n, 0);
    dfs(0, -1, 1);
    for (auto c : colors) {
        cout << c << endl;
    }
    return 0;

}
