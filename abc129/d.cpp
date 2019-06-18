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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) {
        cin >> s[i];
    }

    vector<vector<LL>> left(h, vector<LL>(w, 0));
    vector<vector<LL>> right(h, vector<LL>(w, 0));
    vector<vector<LL>> up(h, vector<LL>(w, 0));
    vector<vector<LL>> down(h, vector<LL>(w, 0));


    rep(y, h) {
        int acc = 0;
        rep(x, w) {
            if (s[y][x] == '#') {
                acc = 0;
                continue;
            }
            acc++;
            left[y][x] = acc;
        }
    }
    rep(y, h) {
        int acc = 0;
        for (int x = w - 1; x >= 0; x--) {
            if (s[y][x] == '#') {
                acc = 0;
                continue;
            }
            acc++;
            right[y][x] = acc;
        }
    }
    rep(x, w) {
        int acc = 0;
        rep(y, h) {
            if (s[y][x] == '#') {
                acc = 0;
                continue;
            }
            acc++;
            up[y][x] = acc;
        }
    }
    rep(x, w) {
        int acc = 0;
        for (int y = h - 1; y >= 0; y--) {
            if (s[y][x] == '#') {
                acc = 0;
                continue;
            }
            acc++;
            down[y][x] = acc;
        }
    }
    LL ans = 0;
    rep(y, h) {
        rep(x, w) {
            ans = max(ans, left[y][x] + right[y][x] + up[y][x] + down[y][x] - 3);
        }
    }
    cout << ans << endl;
    return 0;
}
