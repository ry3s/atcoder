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
    int h, w, d; cin >> h >> w >> d;
    map<int, pair<int, int>> m;
    rep(i, h) rep(j, w) {
        int a; cin >> a;
        m[a] = {i, j};
    }
    int q; cin >> q;
    vector<pair<int, int>> query(q);
    rep(i,q) {
        int l, r;
        cin >> l >> r;
        query[i] = {l, r};
    }
    vector<int> acc(100001, 0);
    for (int s = h * w; s >= h * w - d + 1; --s) {
        for (int i = s - d; i >= 0; i -= d) {
            auto yx = m[i];
            auto nyx = m[i + d];
            int cost = abs(nyx.first - yx.first) + abs(nyx.second - yx.second);
            acc[i] = acc[i + d] + cost;
        }
    }
    for (auto lr : query) {
        int l = lr.first;
        int r = lr.second;
        cout << acc[l] - acc[r] << endl;
    }
}
