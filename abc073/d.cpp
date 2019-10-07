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
    const LL INF = (1LL << 60);
    rep(k, n) rep(i, n) if (dist[i][k] != INF) {
        rep(j, n) if (dist[k][j] != INF) {
            dist[i][j]= min(dist[i][j] , dist[i][k] + dist[k][j]);
            if (j == k and dist[j][k] < 0) return false;
        }
    }
    return true;
}
int main() {
    int N, M, R; cin >> N >> M >> R;
    vector<int> r(R);
    rep(i, R) cin >> r[i], --r[i];

    vector<vector<LL>> dist(N, vector<LL>(N, INF));
    rep(i, M) {
        int a, b, c; cin >> a >> b >> c;
        --a, --b;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    warshall_floyd(dist);

    sort(r.begin(), r.end());
    LL ans = INF;
    do {
        LL d = 0;
        rep(i, R - 1) {
            d += dist[r[i]][r[i + 1]];
        }
        ans = min(ans, d);
    } while (next_permutation(r.begin(), r.end()));

    cout << ans << endl;
}
