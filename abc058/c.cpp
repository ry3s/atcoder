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
    vector<vector<int>> count(n, vector<int>(26, 0));
    rep(i, n) {
        string s; cin >> s;
        for (auto &ch: s) ++count[i][ch - 'a'];
    }

    vector<int> common(26, 0);
    rep(i, 26) {
        int mini = 1e9;
        rep(j, n) {
            mini = min(mini, count[j][i]);
        }
        common[i] = mini;
    }

    rep(i, 26) {
        rep(j, common[i]) {
            printf("%c", i + 'a');
        }
    }
    cout << endl;
}
