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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;

    vector<pair<int, int> > black;
    vector<vector<int> > table(h, vector<int>(w, 0));
    rep(i, h) {
        rep(j, w) {
            char ch;
            cin >> ch;
            if (ch == '#') {
                black.push_back(make_pair(i, j));
                table[i][j] = 1;
            } else {

            }
        }
    }
    int res = 0;
    rep(i, h) {
        rep(j, w) {
            if (table[i][j] == 1) continue;
            int dist = 1e6;
            for (auto xy : black) {
                int x = xy.first;
                int y = xy.second;
                // if (i == x and j == y) {
                //     dist = 0;
                //     continue;
                // }
                dist = min(dist, (int)abs(i - x) + (int)abs(j - y));
            }
            res = max(res, dist);
        }
    }

    cout << res << endl;

    return 0;
}
