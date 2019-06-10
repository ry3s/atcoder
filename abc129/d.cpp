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
    LL ans = 0;
    rep(y, h) {
        rep(x, w) {
            if (s[y][x] == '#') continue;
            LL res = 1;
            for (int ny = y + 1; ny < h; ny++) {
                if (s[ny][x] == '#') break;
                res++;
            }

            for (int ny = y - 1; ny >= 0; ny--) {
                if (s[ny][x] == '#') break;
                res++;
            }

            for (int nx = x + 1; nx < w; nx++) {
                if (s[y][nx] == '#') break;
                res++;
            }

            for (int nx = x - 1; nx >= 0; nx--) {
                if (s[y][nx] == '#') break;
                res++;
            }

            ans = max(ans, res);
        }
    }
    cout << ans << endl;
    return 0;
}
