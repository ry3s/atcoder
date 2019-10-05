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
    int A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;

    double max_dens = -1.0;
    pair<LL, LL> ans;
    rep(a, 31) rep(b, 31) rep(c, 301) rep(d, 301) {
        LL water = 100 * A * a + 100 * B * b ;
        LL sugar = C * c + D * d;
        if (water == 0 or water + sugar > F) break;
        if (water * E / 100 >= sugar) {
            double density = 100. * sugar / (double)(water + sugar);
            if (max_dens < density) {
                ans = {water + sugar, sugar};
                max_dens = density;
            }
        }
    }
    cout << ans.first << " " << ans.second << endl;
}
