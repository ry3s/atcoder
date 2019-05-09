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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > edge(n, vector<int>(n, 0));

    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edge[x][y] = edge[y][x] = 1;
    }

    int ans = 0;
    for (int bit = 1; bit < (1 << n); bit++) {
        int t = bitset<12>(bit).count();
        if (t <= ans) continue;

        bool flag = true;
        rep(i, n) {
            rep(j, i) {

                if((bit >> i & bit >> j & 1)
                   and edge[i][j] != 1) {
                    flag = false;
                }
            }
        }

        if(flag) ans = t;
    }
    cout << ans << endl;
    return 0;
}
