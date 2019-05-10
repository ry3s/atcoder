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

bool is_all_visited(vector<string> &chart, vector<vector<bool> > &visited) {
    rep(i, 10) {
        rep(j, 10) {
            if (chart[i][j] == 'o' and visited[i][j] == false) {
                return false;
            }

        }
    }
    return true;
}
int main() {
    vector<string > chart(10);

    rep(i, 10) {
        cin >> chart[i];
    }

    rep(i, 10) {
        rep(j, 10) {
            // DFS
            stack<pair<int, int> > sta;
            vector<vector<bool> > visited(10, vector<bool>(10, false));
            sta.push(make_pair(i, j));
            visited[i][j] = true;

            while (not sta.empty()) {
                auto xy = sta.top();
                sta.pop();
                int x = xy.first;
                int y = xy.second;

                rep(i, 4) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 and nx < 10 and ny >= 0 and ny < 10
                        and visited[nx][ny] == false
                        and chart[nx][ny] == 'o') {

                        visited[nx][ny] = true;
                        sta.push(make_pair(nx, ny));
                    }
                }
            }

            if (is_all_visited(chart, visited)) {
                cout << "YES" << endl;
                return 0;
            }

        }
    }

    cout << "NO" << endl;
    return 0;
}
