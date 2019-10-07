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
    map<LL, int> mp;
    rep(i, n) {
        int a; cin >> a;
        ++mp[a];
    }
    vector<pair<LL, int>> v;
    for (const auto &x: mp) {
        if (x.second >= 2) v.push_back(x);
    }
    sort(v.rbegin(), v.rend());

    LL pre = -1;
    for (const auto &x: v) {
        if (pre != -1) {
            cout << pre * x.first << endl;
            return 0;
        }
        else if (x.second >= 4) {
            cout << x.first * x.first << endl;
            return 0;
        }
        else {
            pre = x.first;
        }
    }

    cout << 0 << endl;
}
