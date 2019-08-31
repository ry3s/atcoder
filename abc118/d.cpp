#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <bitset>
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;

const string MINUSINF = "-";
const int cost[10] = { 2, 5, 5, 4, 5, 6, 3, 7, 6 };
void chmax(string &a, string b) {
    if (a == MINUSINF) a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size()) {
        if (a < b) a = b;
    }
}


int main() {
    int n, m; cin >> n >> m;
    vector<int> a(m);
    rep(i, m) {
        cin >> a[i];
    }
    vector<string> dp(11000, MINUSINF);
    dp[0] = "";

    rep(i, n + 1) {
        if (dp[i] == MINUSINF) continue;

        for (auto x : a) {
            chmax(dp[i + cost[x - 1]], dp[i] + (char)('0' + x));

        }
    }
    cout << dp[n] << endl;
}
