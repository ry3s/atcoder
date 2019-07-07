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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
using LL = long long int;
using ULL = unsigned long long;

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> xs(n, vector<int>(d, 0));
    rep(i, n) rep(j, d) {
        cin >> xs[i][j];
    }
    int ans = 0;
    rep(i, n - 1) {
        for (int j = i + 1; j < n; j++) {
            int dist = 0;
            rep(k, d) {
                dist += (xs[i][k] - xs[j][k])  * (xs[i][k] - xs[j][k]);
            }
            if (ceil(sqrt(dist)) == floor(sqrt(dist))) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
