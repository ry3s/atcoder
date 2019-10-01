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
    map<int, int> m;
    rep(i, n) {
        int a; cin >> a;
        ++m[a];
    }
    vector<pair<int, int>> v;
    for (auto e: m) {
        v.push_back({e.second, e.first});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    rep(i, v.size() - k) {
        ans += v[i].first;
    }
    cout << ans << endl;
}
