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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
    int r, c;
    cin >> r >> c;
    int sy, sx;
    cin >> sy >> sx;
    sy--; sx--;
    int gy, gx;
    cin >> gy >> gx;
    gy--; gx--;

    vector<vector<char> > board(r, vector<char>(c));
    rep(i, r) {
        rep(j, c) {
            cin >> board[i][j];
        }
    }
    // BFS
    queue<pair<int, int> > qu;
    vector<vector<int> > dist(r, vector<int>(c, 1e9));
    qu.push(make_pair(sy, sx));
    dist[sy][sx] = 0;
    while (not qu.empty()) {
        auto yx = qu.front();
        qu.pop();
        int y = yx.first;
        int x = yx.second;
        rep(i, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 and ny < r and nx >= 0 and nx < c
                and dist[ny][nx] == 1e9
                and board[ny][nx] == '.') {
                dist[ny][nx] = dist[y][x] + 1;
                qu.push(make_pair(ny, nx));
            }
        }
    }
    cout << dist[gy][gx] << endl;
    return 0;
}
