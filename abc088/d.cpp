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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int bfs(vector<vector<char> > &board, int h, int w) {
    queue<pair<int, int> > qu;
    qu.push(make_pair(0, 0));
    vector<vector<int> > dist(h, vector<int>(w, -1));
    dist[0][0] = true;
    while (not qu.empty()) {
        auto yx = qu.front();
        qu.pop();
        int y = yx.first;
        int x = yx.second;
        rep(i, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 and ny < h and nx >= 0 and nx < w
                and board[ny][nx] == '.' and dist[ny][nx] == -1) {
                qu.push(make_pair(ny, nx));
                dist[ny][nx] = dist[y][x] + 1;

            }
        }
    }
    return dist[h - 1][w - 1];

}

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char> > board(h, vector<char>(w));
    int num_white = 0;
    rep(i, h) {
        rep(j, w) {
            cin >> board[i][j];
            if (board[i][j] == '.') num_white++;
        }
    }
    int ans = bfs(board, h, w);
    if (ans == -1) {
        cout << -1 << endl;
    } else {
        cout << num_white - ans << endl;
    }

    return 0;
}
