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
    int h, w; cin >> h >> w;

    vector<vector<LL>> magic(10, vector<LL>(10, 0));
    rep(i, 10) rep(j, 10) {
        cin >> magic[i][j];
    }
    warshall_floyd(magic);

    map<int, int> m;
    rep(i, h) rep(j, w) {
        int a; cin >> a;
        if (a == -1) continue;
        ++m[a];
    }

    int ans = 0;
    for (auto e: m) {
        ans += magic[e.first][1] * e.second;
    }
    cout << ans << endl;
}
