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
    int n, k; cin >> n >> k;
    vector<vector<int>> qs(n, vector<int>(k));
    rep(i, n) {
        rep(j, k) {
            cin >> qs[i][j];
        }
    }


    for (int bit = 0; bit < (int)pow(k, n); bit++) {
        int mask = bit;
        int res = 0;
        for (int pos = 0; pos < n; pos++) {
            res ^= qs[pos][mask % k];
            mask /= k;
        }
        if (res == 0) {
            cout << "Found" << endl;
            return 0;
        }
    }
    cout << "Nothing" << endl;
}
