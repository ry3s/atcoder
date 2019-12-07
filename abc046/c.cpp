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
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    rep(i, n) {
        int t, a; cin >> t >> a;
        v[i] = {t, a};
    }

    long long x = 1, y = 1;
    for (int i = 0; i < n; i++) {
        auto t = v[i].first;
        auto a = v[i].second;
        long long nx = x / t;
        long long ny = y / a;

        if (x % t != 0) nx++;
        if (y % a != 0) ny++;
        long long co = max(nx, ny);
        x = co * t;
        y = co * a;
    }

    cout << x + y << endl;
}
