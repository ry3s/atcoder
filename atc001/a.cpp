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
    int h, w;
    cin >> h >> w;

    vector<vector<char> > c(h, vector<char>(w));
    int sx, sy;
    rep(i, h) {
        rep(j, w) {
            cin >> c[i][j];
            if (c[i][j] == 's') {
                sy = i;
                sx = j;
            }
        }
    }

    stack<pair<int, int> > st;
    vector<vector<bool> > visited(h, vector<bool>(w, false));
    st.push(make_pair(sx, sy));
    while (not st.empty()) {
        auto xy = st.top();
        st.pop();
        int x = xy.first;
        int y = xy.second;
        visited[y][x] = true;

        rep(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 and nx < w and ny >= 0 and ny < h
                and visited[ny][nx] == false) {

                if (c[ny][nx] == 'g') {
                    cout << "Yes" << endl;
                    return 0;
                }
                if (c[ny][nx] == '.') {
                    st.push(make_pair(nx, ny));
                }

            }
        }

    }
    cout << "No" << endl;
    return 0;
}
