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
using Edges = vector<pair<int, int>>;
using Graph = vector<Edges>;
const long long INF = (1LL << 60);

bool warshall_floyd(vector<vector<LL>> &dist) {
    int n = dist.size();
    rep(k, n) rep(i, n) if (dist[i][k] != INF) {
        rep(j, n) if (dist[k][j] != INF) {
            dist[i][j]= min(dist[i][j] , dist[i][k] + dist[k][j]);
            if (j == k and dist[j][k] < 0) return false;
        }
    }
    return true;
}


int main() {
    int n, m; cin >> n >> m;

    vector<int> a(m, 0), b(m, 0), c(m, 0);
    vector<vector<LL>> dist(n, vector<LL>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0; // ここがポイント
    }
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        --a[i]; --b[i];
        dist[a[i]][b[i]] = c[i];
        dist[b[i]][a[i]] = c[i];

    }

    warshall_floyd(dist);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        bool ok = false;
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < n; q++) {
                if (dist[p][q] == dist[p][a[i]] + c[i] + dist[b[i]][q]) {
                    ok = true;
                }
            }
        }
        if (!ok) ++ans;
    }
    cout << ans << endl;
}
