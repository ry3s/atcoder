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
    map<int, int> m;
    rep(i, n) { int a; cin >> a; ++m[a]; }

    int mini = m.begin()->first;
    int maxi = m.rbegin()->first;

    int ans = 0;
    for (int i = mini - 1; i <= maxi + 1; i++) {
        ans = max(ans, m[i] + m[i - 1] + m[i + 1]);
    }
    cout << ans << endl;
}
