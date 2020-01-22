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
const double EPS =  1e-7;
const double PI  = acos(-1);

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
// cf: imos 法
void shakutori() {
    int right = 0;
    for (int left = 0; left < 100; ++left) {
        while (right < 100 /* && (right を 1 個進めたときに条件を満たす)*/) {
            /* 実際に right を 1 進める */
            // ex: sum += a[right];
            ++right;
        }

    // 半開区間
    /* break した状態で right は条件を満たす最大なので、何かする */
    // ex: res += (right - left);

    /* left をインクリメントする準備 */
    // ex: if (right == left) ++right;
    // ex: else sum -= a[left];
    }
}

// めぐる式二分探索
int binary_search(const vector<int>& v, int key) {
    // v[index] >= key という条件を満たす最小の index を見つける

    int ng = -1;
    int ok = static_cast<int>(v.size());

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (v[mid] >= key) ok = mid;
        else ng = mid;
    }
    return ok;
}
int64_t gcd(int64_t a, int64_t b) {
    if (a < b) return gcd(b, a);

    int64_t r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}
int64_t lcm(int64_t a, int64_t b) {
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
int64_t power(int64_t base, int64_t n, int64_t mod) {
    int64_t ret = 1;

    while (n > 0) {
        if (n & 1) {
            (ret *= base) %= mod;
        }
        (base *= base) %= mod;
        n >>= 1;
    }
    return ret;
}
bool is_prime(int64_t x) {
    for (int64_t i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
// 約数列挙
vector<int64_t> make_divisors(int64_t n) {
    vector<int64_t> res;

    for (int64_t i = 1LL; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }

    sort(res.begin(), res.end());
    return res;
}
// 素因数分解
map<int64_t, int> prime_factor(int64_t n) {
    map<int64_t, int> ret;

    for (int64_t i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }

    if (n != 1) ret[n] = 1;
    return ret;
}
// 組み合わせ combination
const int MAX_C = 2100;
int64_t com[MAX_C][MAX_C];
const int64_t MOD = 1e9 + 7;
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
template <typename T>
struct Combination {
    vector<T> fac, finv, inv;
    const int64_t MOD = 1e9 + 7;
    Combination(int size)
        : fac(size + 1), finv(size + 1), inv(size + 1) {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < size + 1; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    int64_t com(int n, int k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
};

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

template<typename T>
struct BellmanFord1 {
    struct Edge {
        int from, to; int64_t cost;
        Edge() {}
        Edge(int from, int to, int64_t cost): from(from), to(to), cost(cost) {}
    };

    int n;
    vector<vector<int>> graph;
    vector<int> used, reach;
    BellmanFord1(int n): n(n), graph(n), used(n, 0), reach(n, 0) {}

    vector<Edge> edges;
    void add_edge(int from, int to, int64_t cost) {
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
    int64_t build(int from, int to, bool &neg_loop) {
        rep(i, n) {
            fill(used.begin(), used.end(), 0);
            dfs(i);
            reach[i] = used[to];
        }

        vector<int64_t> dist(n, 1e18);
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
        int from, to; int64_t cost;
        Edge() {}
        Edge(int from, int to, int64_t cost): from(from), to(to), cost(cost) {}
    };
    const int64_t INF = (1LL << 60);
    int n;
    vector<vector<int>> graph;
    vector<int> used, reach;
    vector<int64_t> dist;
    BellmanFord(int n): n(n), graph(n), used(n, 0), reach(n, 0), dist(n, INF) {}

    vector<Edge> edges;
    void add_edge(int from, int to, int64_t cost) {
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
using Graph = vector<vector<pair<int, int64_t>>>;
const int64_t INF = (1LL << 60);
vector<int64_t> dijkstra(const Graph &g, int s) {
    int n = g.size();
    vector<int64_t> dist(n, INF);
    priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> que;

    que.push({0, s});
    dist[s] = 0;
    while(not que.empty()) {
        auto dv = que.top(); que.pop();
        int64_t d = dv.first;
        int v = dv.second;

        if (dist[v] < d) continue;
        for (auto e: g[v]) {
            if (dist[v] + e.second < dist[e.first]) {
                dist[e.first] = dist[v] + e.second;
                que.push({dist[e.first], e.first});
            }
        }
    }
    return dist;
}
bool warshall_floyd(vector<vector<int64_t>> &dist) {
    int n = dist.size();
    const int64_t INF = (1LL << 60);
    rep(k, n) rep(i, n) if (dist[i][k] != INF) {
        rep(j, n) if (dist[k][j] != INF) {
            dist[i][j]= min(dist[i][j] , dist[i][k] + dist[k][j]);
            if (j == k and dist[j][k] < 0) return false;
        }
    }
    return true;
}
