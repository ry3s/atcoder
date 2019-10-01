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
    string s; cin >> s;
    int n = s.size();
    const int INF = 1e9;
    int ans = INF;
    rep(i, n - 1) {
        if (s[i] != s[i + 1]) ans = min(ans, max(i + 1, n - i - 1));
    }
    if (ans == INF) ans = n;
    cout << ans << endl;
}
