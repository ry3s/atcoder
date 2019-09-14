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

using Edges = vector<int>;
using Graph = vector<Edges>;

Graph graph;
vector<int> colors;

bool dfs(int v, int col) {
    colors[v] = col;

    for (auto e : graph[v]) {
        if (colors[e] == col) return false;
        if (colors[e] == 0 and not dfs(e, -col)) return false;
    }
    return true;
}

int main() {
    LL n, m; cin >> n >> m;
    graph.assign(n, Edges());
    rep(i, m) {
        int a, b; cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    colors.assign(n, 0);
    if (dfs(0, 1)) {
        LL black = 0, white = 0;
        rep(i, n) {
            if (colors[i] == -1) white++;
            else if (colors[i] == 1) black++;
        }
        cout << white * black - m << endl;
    } else {
        cout << (n * (n - 1)) / 2 - m << endl;
    }
    return 0;
}
