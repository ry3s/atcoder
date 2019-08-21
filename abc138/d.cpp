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
#include <functional>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
using ULL = unsigned long long;

using Graph = vector<vector<int>>;
Graph graph;
vector<LL> counter;
void dfs(int v, int p, LL add) {
    counter[v] += add;
    for (auto x : graph[v]) {
        if (x == p) continue;
        else dfs(x, v, counter[v]);
    }
}
int main() {
    int n, q;
    cin >> n >> q;
    graph = Graph(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<pair<int, int>> query(q);
    rep(i, q) {
        int p, x;
        cin >> p >> x;
        p--;
        query[i] = make_pair(p, x);
    }
    counter = vector<LL>(n, 0);
    for (auto px : query) {
        counter[px.first] += px.second;
    }

    dfs(0, 0, 0);
    for (auto v : counter) {
        cout << v << " ";
    }
    cout << endl;
}
