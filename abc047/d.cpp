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
    long long n, t; cin >> n >> t;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];

    long long mini = a[0];
    map<long long, int> diffs;
    rep(i, n - 1) {
        mini = min(mini, a[i]);
        auto diff = a[i + 1] - mini;
        diffs[diff]++;
    }
    auto ans = *(diffs.rbegin());
    cout << ans.second << endl;
}
