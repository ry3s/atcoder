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
    int n;
    cin >> n;
    vector<LL> ws(n);
    rep(i, n) {
        cin >> ws[i];
    }
    //sort(ws.begin(), ws.end());

    LL ans = 1010101010;
    rep(i, n) {
        vector<LL> ls, rs;
        rep(l, i) {
            ls.push_back(ws[l]);
        }
        for (LL r = i; r < n; r++) {
            rs.push_back(ws[r]);
        }
        LL res = 0;
        rep(i,ls.size()) {
            res += ls[i];
        }
        rep(i, rs.size()) {
            res -= rs[i];
        }
        res = abs(res);
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
