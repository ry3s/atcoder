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
    int n, k; cin >> n >> k;
    vector<pair<LL, LL>> xy(n);
    rep(i, n) {
        LL x, y; cin >> x >> y;
        xy[i] = {x, y};
    }
    set<int> xx, yy;
    for (auto e: xy) {
        xx.insert(e.first); yy.insert(e.second);
    }

    LL ans = -1;
    for (int sx: xx)
        for (int sy: yy)
            for (int tx: xx)
                for (int ty: yy)  if (sx <= tx and sy <= ty) {
                        LL sm = 1LL * (tx - sx) * (ty - sy);

                        int cnt = 0;
                        rep(i, n) if (sx <= xy[i].first
                                      and xy[i].first <= tx
                                      and sy <= xy[i].second
                                      and xy[i].second <= ty) cnt++;

                        if (k <= cnt) {
                            if (ans < 0) ans = sm;
                            ans = min(ans, sm);
                        }
                }
    cout << ans << endl;
}
