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
const int dx[9] = { 0, -1, 0, 1, 1,  1,  0, -1, -1 };
const int dy[9] = { 0,  1, 1, 1, 0, -1, -1, -1, 0 };

int main() {
    long long h, w, n; cin >> h >> w >> n;
    vector<pair<long long , long long>> points(n);
    for (int i = 0; i < n; i++) {
        long long a, b; cin >> a >> b;
        points[i] = { a, b };
    }

    map<pair<long long, long long>, long long> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            int ny = points[i].first + dy[j];
            int nx = points[i].second + dx[j];

            if (2 <= ny && ny < h && 2 <= nx && nx < w) {
                mp[{ny, nx}]++;
            }
        }
    }
    map<int, long long> ans;
    for (int i = 1; i < 10; i++) {
        ans[i] = 0;
    }
    long long sum0 = 0;
    for (auto pn: mp) {
        auto cnt = pn.second;
        ans[cnt]++;
        sum0++;
    }
    cout << (h - 2) * (w - 2) - sum0 << endl;
    for (auto e: ans) {
        cout << e.second << endl;
    }
}
