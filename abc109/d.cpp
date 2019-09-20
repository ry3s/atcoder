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
#include <tuple>
#include <bitset>
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
using ULL = unsigned long long;

using pint = pair<int, int>;
using ppint = pair<pint, pint>;
int main() {
    int h, w; cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    int num_odd = 0;
    rep(i, h) rep(j, w) {
        cin >> a[i][j];
        if (a[i][j] & 1) ++num_odd;
    }

    vector<ppint> res;
    int num = 0;
    int y = 0, x = 0;
    rep(it, h * w) {
        if (a[y][x] & 1) ++num;

        int ny = y, nx = x;
        if (y % 2 == 0) {
            if (nx == w - 1) ++ny;
            else ++nx;
        } else {
            if (nx == 0) ++ny;
            else --nx;
        }

        if (num & 1) if (num < num_odd) res.push_back(ppint(pint(y, x), pint(ny, nx)));
        y = ny; x = nx;

    }
    cout << res.size() << endl;
    for (auto p : res) {
        int y, x, ny, nx;
        tie(y, x) = p.first;
        tie(ny, nx) = p.second;
        cout << y + 1 << " " << x + 1 << " " << ny + 1<< " " << nx + 1<< endl;
    }
}
