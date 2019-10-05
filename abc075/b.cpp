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

int main() {
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    const int dx[] = { 1,  1,  0, -1, -1, -1, 0, 1 };
    const int dy[] = { 0, -1, -1, -1,  0,  1, 1, 1 };

    vector<vector<int>> ans(h, vector<int>(w, -1));

    rep(i, h) {
        rep(j, w) if (s[i][j] == '.') {
            int cnt = 0;
            rep(k, 8) {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny >= 0 and ny < h and nx >= 0 and nx < w) {
                    if (s[ny][nx] == '#') ++cnt;
                }

            }
            ans[i][j] = cnt;
        }
    }

    rep(i, h) {
        rep(j, w) {
            if (ans[i][j] == -1) cout << '#';
            else cout << ans[i][j];
        }
        cout << "\n";
    }
}
