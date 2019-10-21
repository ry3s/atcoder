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

const LL INF = (1LL << 60);

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
    long long n, m, l; cin >> n >> m >> l;
    vector<vector<LL>> dist(n, vector<LL>(n, INF));
    rep(i, m) {
        int a, b; LL c;
        cin >> a >> b >> c;
        --a, --b;
        dist[a][b] = dist[b][a] = c;
    }
    warshall_floyd(dist);
    vector<vector<LL>> dist2(n, vector<LL>(n, INF));
    rep(i, n) rep(j, n) {
        if (dist[i][j] <= l) dist2[i][j] = dist2[j][i] = 1;
    }
    warshall_floyd(dist2);

    int q; cin >> q;
    rep(i, q) {
        int s, t; cin >> s >> t;
        --s, --t;
        LL d = dist2[s][t];
        if (d == INF) {
            cout << -1 << endl;
        } else {
            cout << d - 1 << endl;
        }
    }
}
