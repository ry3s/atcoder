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
    vector<vector<int>> f(n, vector<int>(10));
    rep(i, n) rep(j, 10) cin >> f[i][j];

    vector<vector<LL>> p(n, vector<LL>(11));
    rep(i, n) rep(j, 11) cin >> p[i][j];

    int ans = -1e9;
    for (int mask = 1; mask < (1 << 10); mask++) {
        int sum = 0;

        rep(i, n) {
            int c = 0;
            rep(j, 10) if (mask & (1 << j)) if (f[i][j]) c++;
            sum += p[i][c];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
