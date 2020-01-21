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

const int dx[] = { 1, 0, -1, 0};
const int dy[] = { 0, 1, 0, -1};

int bfs(int y, int x,
         int h, int w, vector<string> arr) {
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pair<int, int>> que;

    int res = 0;
    dist[y][x] = 0;
    que.push({y, x});
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        res = max(res, dist[cur.first][cur.second]);

        rep(i, 4) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (arr[ny][nx] == '#') continue;
            if (dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[cur.first][cur.second] + 1;
            que.push({ny, nx});
        }
    }
    return res;
}
int main() {
    int h, w; cin >> h >> w;
    vector<string> arr(h);
    rep(i, h) cin >> arr[i];


    int ans = 0;

    for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
            if (arr[y][x] == '#') continue;
            ans = max(ans, bfs(y, x, h, w, arr));
        }
    }
    cout << ans << endl;
}
