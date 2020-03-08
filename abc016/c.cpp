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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using Graph = vector<vector<int>>;
Graph g;
vector<bool> visited;
vector<int> cnt;
void dfs(int cur, int par, int start, int depth) {
    if (depth == 2) {
        for (auto next: g[cur]) {
            if (next == start) return;
        }
        if (visited[cur]) {
            cnt[start]++;
            visited[cur] = false;
        }
    } else {
        for (auto next: g[cur]) {
            if (next != par) {
                dfs(next, cur, start, depth + 1);
            }
        }
    }

}
int main() {
    int n, m; cin >> n >> m;
    g.resize(n);
    visited.assign(n, false);
    cnt.assign(n, 0);
    rep(i, m) {
        int a, b; cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i, n) {
        visited.assign(n, true);
        dfs(i, -1, i, 0);
        cout << cnt[i] << endl;
    }
}
