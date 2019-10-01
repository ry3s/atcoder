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
    const int max_time = 1e5 + 1;
    int n, C; cin >> n >> C;
    vector<vector<int>> table(C, vector<int>(max_time, 0));
    rep(i, n) {
        int s, t, c; cin >> s >> t >> c;
        --c;
        table[c][s]++; table[c][t + 1]--;
    }

    rep(i, C) {
        rep(j, max_time) {
            table[i][j + 1] += table[i][j];
        }
    }

    int ans = 0;
    rep(j, max_time) {
        int cnt = 0;
        rep(i, C) {
            if (table[i][j]) ++cnt;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}
