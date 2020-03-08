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

bool dfs(int i, int acc, int k, vector<vector<int>> qs) {
    int n = qs.size();
    if (i == n) {
        return acc == 0;
    }
    rep(j, k) {
        if (dfs(i + 1, acc ^ qs[i][j], k, qs)) return true;
    }
    return false;
}
int main() {
    int n, k; cin >> n >> k;
    vector<vector<int>> qs(n, vector<int>(k));
    rep(i, n) {
        rep(j, k) {
            cin >> qs[i][j];
        }
    }
    if (dfs(0, 0, k, qs)) cout << "Found" << endl;
    else cout << "Nothing" << endl;
}
