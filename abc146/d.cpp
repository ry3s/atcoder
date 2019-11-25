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

using Graph = vector<vector<int>>;
Graph graph;
map<pair<int, int>, int> colors;
int max_color = 0;

void dfs(int cur, int par, int color) {
    for (auto next: graph[cur]) {
        if (next == par) continue;

        color += 1;
        color %= max_color;

        int a = cur, b = next;
        if (a > b) swap(a, b);
        colors[{a, b}] = color;
        dfs(next, cur, color);
    }
}
int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n; cin >> n;
    graph.resize(n);
    vector<int> a(n - 1), b(n - 1);

    rep(i, n - 1) {
        cin >> a[i] >> b[i];
        --a[i]; --b[i];

        if (a[i] > b[i]) swap(a[i], b[i]);

        graph[a[i]].push_back(b[i]);
        graph[b[i]].push_back(a[i]);
    }

    int index = 0;
    rep(i, n) {
        if (max_color < (int)graph[i].size()) {
            index = i;
            max_color = graph[i].size();
        }
    }

    dfs(index, -1, 0);

    cout << max_color << endl;
    rep(i, n - 1) {
        cout << colors[{a[i], b[i]}] + 1 << endl;
    }
}
