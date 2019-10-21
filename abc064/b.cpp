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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ret = 1e9;
    rep(i, n) {
        int ans = 0;
        int prev = a[i];
        for (int j = i - 1; j >= 0; --j) {
            ans += abs(a[j] - prev);
            prev = a[j];
        }
        prev = a[i];
        for (int j = i + 1; j < n; ++j) {
            ans += abs(a[j] - prev);
            prev = a[j];
        }
        ret = min(ret, ans);
    }
    cout << ret << endl;
}
