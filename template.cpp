#include <cstdio>
#include <climits>
#include <cstdlib>
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
#include <list>
#include <set>
#include <bitset>
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
using LL = long long int;
using ULL = unsigned long long;


// optional
#define EPS (1e - 7)
#define PI (acos(-1))


// DFS template
using myGraph = vector<vector<int>>;
vector<bool> visited;
void dfs(const myGraph &graph, int v) {
    visited[v] = true;

    for (auto next_v : graph[v]) {
        if (visited[next_v]) continue;

        dfs(graph, next_v);
    }
}

// 立っているビットを数える
int count_bits(int bits) {
    int num = 0;
    while (bits != 0) {
        num++;
        bits &= bits - 1;
    }
    return num;
}

// 構文解析
#include <cctype>
using State = string::const_iterator;
// !!! else break;


// 累積和
vector<int> a(100);
vector<int> acc(100 + 1, 0);
void ruiseki_wa() {
    rep(i, 100) { acc[i + 1] = acc[i] + a[i]; };
}
// ２次元累積
// acc[x + 1][y + 1] = acc[x][y = 1] + acc[x + 1][y] - acc[x][y] + a[x][y]

// しゃくとり法
void shakutori() {
    int right = 0;
    for (int left = 0; left < 100; ++left) {
        while (right < 100 /* && (right を 1 個進めたときに条件を満たす)*/) {
            /* 実際に right を 1 進める */
            // ex: sum += a[right];
            ++right;
        }

    /* break した状態で right は条件を満たす最大なので、何かする */
    // ex: res += (right - left);

    /* left をインクリメントする準備 */
    // ex: if (right == left) ++right;
    // ex: else sum -= a[left];
    }
}

int gcd(int a, int b) {
    if (a < b) return gcd(b, a);

    int r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}


void bit_exhaustive_search() {
    int n = 100;

    for (int bit = 0; bit < (1 << n); bit++) {
        rep(i, n) {
            if (bit & (1 << i)) {
                // 適当な処理
            }
        }
    }
}

// power(x, n, mod) ::= (x ^ n) % mod
int power(int base, int n, int mod) {
    int ret = 1;

    while (n > 0) {
        if (n & 1) {
            (ret *= base) %= mod;
        }
        (base *= base) %= mod;
        n >>= 1;
    }
    return ret;
}

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

// 組み合わせ combination
const int MAX_C = 2100;
LL com[MAX_C][MAX_C];
const LL MOD = 1e9 + 7;
void calc_com() {
    memset(com, 0, sizeof(com));
    com[0][0] = 1;
    for (int i = 1; i < MAX_C; ++i) {
        com[i][0] = 1;
        for (int j = 1; j < MAX_C; ++j) {
            com[i][j] = (com[i-1][j-1] + com[i-1][j]) % MOD;
        }
    }
}

template<typename T>
struct Combination {
    vector<T> fact, rfact, inv;
    const LL MOD = 1e9 + 7;
    Combination(int size) : fact(size + 1), rfact(size + 1), inv(size + 1) {
        fact[0] = fact[1] = 1;
        rfact[0] = rfact[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= size; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            rfact[i] = rfact[i - 1] * inv[i] % MOD;
        }
    }
    LL com(int n, int k) {
        if (n < k) return 0;
        if (n < 0 or k < 0) return 0;
        return fact[n] * (rfact[k] * rfact[n - k] % MOD) % MOD;
    }

};

// Graph
using Weight = int;
struct Edge {
    int src, dst;
    Weight weight;
    Edge(int src, int dst, Weight weight) :
        src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

using Edges = vector<Edge>;
using Graph = vector<Edges>;

void dijkstra(const Graph &g, int s, vector<Weight> &dist, vector<int> &prev) {
    const int INF = 1e9;
    int n = g.size();
    dist.assign(n, INF); dist[s] = 0;
    prev.assign(n, -1);
    priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
    for (Q.push(Edge(-2, s, 0)); not Q.empty(); ) {
        Edge e = Q.top();
        Q.pop();

        if (prev[e.dst] != -1) continue;

        prev[e.dst] = e.src;
        for (auto f = g[e.dst].begin(); f != g[e.dst].end(); f++) {
            if (dist[f->dst] > e.weight+f->weight) {
                dist[f->dst] = e.weight+f->weight;
                Q.push(Edge(f->src, f->dst, e.weight+f->weight));
            }
        }
    }
}
vector<int> build_path(const vector<int> &prev, int t) {
    vector<int> path;
    for (int u = t; u >= 0; u = prev[u]) {
        path.push_back(u);
    }
    reverse(path.begin(), path.end());
    return path;
}
void longest_common_subsequence() {
    string s, t;
    cin >> s;
    cin >> t;
    vector<vector<int> > dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    int n = s.length();
    int m = t.length();

    rep(i, n) {
        rep(j, m) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    cout << dp[n][m] << endl;;

}
void edit_distance() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    rep(i, n + 1) {
        dp[i][0] = i;
    }
    rep(j, m + 1) {
        dp[0][j] = j;
    }
    rep(i, n) rep(j, m){
        if (s1[i] == s2[j]) {
            dp[i + 1][j + 1] = dp[i][j];
        } else {
            dp[i + 1][j + 1] = min({dp[i][j + 1] + 1, dp[i + 1][j] + 1, dp[i][j] + 1});
        }
    }
    cout << dp[n][m] << endl;

}
// bit DP
// dp[S] = min{i が集合 S に含まれるとき} (dp[S - {i}] + cost(S \ {i}, i));


// void dfs(int v, int parent) {
//     for (auto nv : graph[v]) {
//         if (nv == parent) continue; // 逆流防止
//         dfs(nv, v);
//     }
// }
// int main() {
//     int root = 0;
//     dfs(root, -1); // root の parent は -1
// }

template<typename T>
struct BellmanFord1 {
    struct Edge {
        int from, to; LL cost;
        Edge() {}
        Edge(int from, int to, LL cost): from(from), to(to), cost(cost) {}
    };

    int n;
    vector<vector<int>> graph;
    vector<int> used, reach;
    BellmanFord1(int n): n(n), graph(n), used(n, 0), reach(n, 0) {}

    vector<Edge> edges;
    void add_edge(int from, int to, LL cost) {
        edges.push_back(Edge(from, to, cost));
        graph[from].push_back(to);
    }

    void dfs(int v) {
        if (used[v]) return;

        used[v] = 1;
        for (int u : graph[v]) {
            dfs(u);
        }
    }
    LL build(int from, int to, bool &neg_loop) {
        rep(i, n) {
            fill(used.begin(), used.end(), 0);
            dfs(i);
            reach[i] = used[to];
        }

        vector<LL> dist(n, 1e18);
        dist[from] = 0;

        rep(i, n) {
            bool updated = false;

            for (auto e : edges) {
                if (not reach[e.from]
                    or not reach[e.to]
                    or dist[e.from] == 1e18) continue;

                if (dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to] = dist[e.from] + e.cost;
                    updated = true;
                }
            }

            if (not updated) break;
            if (i == n - 1) {
                neg_loop = true;
                return 1e18;
            }
        }
        neg_loop = false;
        return dist[to];
    }
};
struct BellmanFord {
    struct Edge {
        int from, to; LL cost;
        Edge() {}
        Edge(int from, int to, LL cost): from(from), to(to), cost(cost) {}
    };
    const LL INF = (1LL << 60);
    int n;
    vector<vector<int>> graph;
    vector<int> used, reach;
    vector<LL> dist;
    BellmanFord(int n): n(n), graph(n), used(n, 0), reach(n, 0), dist(n, INF) {}

    vector<Edge> edges;
    void add_edge(int from, int to, LL cost) {
        edges.push_back(Edge(from, to, cost));
        graph[from].push_back(to);
    }
    void build(int s, bool &neg_loop) {
        neg_loop = false;
        dist[s] = 0;
        rep(i, n) {
            for (auto e : edges) {
                if (dist[e.from] != INF and dist[e.from] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[e.from] + e.cost;

                    if (i == n - 1) {
                        neg_loop = true;
                        return;
                    }
                }
            }
        }
    }
};
struct UnionFind {
    vector<int> par;

    UnionFind(int n) {
        par.assign(n, -1);
    }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    bool is_same(int x, int y) {
        return root(x) == root(y);
    }
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x) {
        return -par[root(x)];
    }
};
// reference:
// Spaghetti Source logo 各種アルゴリズムの C++ による実装
// http://www.prefield.com/algorithm/index.html

// しゃくとり法 (尺取り法) の解説と、それを用いる問題のまとめ
// https://qiita.com/drken/items/ecd1a472d3a0e7db8dce
