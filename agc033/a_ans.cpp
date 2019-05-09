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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;

    queue<pair<int, int> > que;
    vector<vector<int> > table(h, vector<int>(w, 0));
    rep(i, h) {
        rep(j, w) {
            char ch;
            cin >> ch;
            if (ch == '#') {
                que.push(make_pair(i, j));
                table[i][j] = 0;
            } else {
                table[i][j] = -1;
            }
        }
    }

    // DFS
    while (not que.empty()) {
        auto xy = que.front();
        que.pop();

        int x = xy.first;
        int y = xy.second;

        rep(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 and nx < h
                and ny >= 0 and ny < w
                and table[nx][ny] == -1) {

                que.push(make_pair(nx, ny));
                table[nx][ny] = table[x][y] + 1;
            }
        }
    }

    int ans = 0;
    rep(i, h) {
        rep(j, w) {
            ans = max(ans, table[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}
