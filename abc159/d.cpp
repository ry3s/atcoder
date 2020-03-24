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
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    map<uint64_t, uint64_t> mp;
    for (auto& x: a) {
        mp[x]++;
    }

    uint64_t sum = 0;
    for (pair<uint64_t, uint64_t> p: mp) {
        if (p.second != 1) {
            sum += p.second * (p.second - 1) / 2;
        }
    }

    for (const auto& g: a) {
        auto x = mp[g];
        uint64_t ans = sum - x * (x - 1) / 2
            + (((x - 1) * (x - 2) / 2) > 0 ? ((x - 1) * (x - 2) / 2) : 0);
        cout<< ans << endl;
    }
}
