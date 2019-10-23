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
    vector<string> a(h);
    rep(i, h) cin >> a[i];

    vector<vector<char>> ans(h + 2, vector<char>());
    rep(i, h + 2) {
        if (i == 0 or i == h + 1) {
            rep(j, w + 2) ans[i].push_back('#');
        } else {
            rep(j, w + 2) {
                if (j == 0 or j == w + 1) ans[i].push_back('#');
                else ans[i].push_back(a[i - 1][j - 1]);
            }
        }
    }
    rep(i, h + 2) {
        rep(j, w + 2) cout << ans[i][j];
        cout << endl;
    }
}
