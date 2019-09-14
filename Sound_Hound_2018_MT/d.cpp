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

using Edges = vector<tuple<int, LL, LL>>;
using Graph = vector<Edges>;

vector<LL> dijkstra(int s, int i) {

}
int main() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    Graph graph(n);
    rep(i, m) {
        int u, v; LL a, b;
        cin >> u >> v >> a >> b;
        u--; v--;
        graph[u].push_back(make_tuple(v, a, b));
        graph[v].push_back(make_tuple(u, a, b));
    }


}
