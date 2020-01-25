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

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
const int64_t INF = (1LL << 60);
vector<vector<int64_t>>
dijkstra(const vector<vector<char>> &mas,
         pair<int, int> s,
         int64_t x) {
    int h = mas.size();
    int w = mas[0].size();
    vector<vector<int64_t>> dist(h, vector<int64_t>(w, INF));
    priority_queue<pair<int64_t, pair<int, int>>,
                   vector<pair<int64_t, pair<int, int>>>,
                   greater<>> que;

    que.push({ 0, s });
    dist[s.first][s.second] = 0;
    while (!que.empty()) {
        // rep(i, h) {
        //     rep(j, w) {
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        auto dv = que.top(); que.pop();
        int64_t d = dv.first;
        auto cur = dv.second;

        if (dist[cur.first][cur.second] < d) continue;
        rep(i, 4) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (ny >= 0 && ny < h && nx >= 0 && nx < w) {
                if (mas[ny][nx] == '#') {
                    if (dist[cur.first][cur.second] + x < dist[ny][nx]) {
                        dist[ny][nx] = dist[cur.first][cur.second] + x;
                        que.push({ dist[ny][nx], { ny, nx } });
                    }
                } else if (dist[cur.first][cur.second] + 1 < dist[ny][nx]){
                    dist[ny][nx] = dist[cur.first][cur.second] + 1;
                    que.push({ dist[ny][nx], { ny, nx } });
                }
            }
        }
    }

    return dist;
}
bool
solve(pair<int, int> s, pair<int, int> g,
      int64_t x, int64_t limit_time,
      const vector<vector<char>> mas) {
    auto dist = dijkstra(mas, s, x);
    // debug(dist[g.first][g.second]);
    return dist[g.first][g.second] <= limit_time;
}
int main() {
    int64_t h, w, t; cin >> h >> w >> t;
    vector<vector<char>> mas(h, vector<char>(w));

    pair<int, int> start, goal; // (y, x)
    rep(i, h) {
        rep(j, w) {
            cin >> mas[i][j];
            if (mas[i][j] == 'S') {
                start = {i, j};
            } else if (mas[i][j] == 'G') {
                goal = {i, j};
            }
        }
    }

    int64_t ok = 1000000000;
    int64_t ng = 0;
    while (abs(ok - ng) > 1) {
        int64_t mid = (ok + ng) / 2;
        // debug(mid);
        if (!solve(start, goal, mid, t, mas)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ng << endl;
}
