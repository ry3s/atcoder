#include <cstdio>
#include <climits>
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
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int n, m, c;

    cin >> n >> m >> c;
    vector<int> b(m);
    rep(i, m) {
        cin >> b[i];
    }
    vector<vector<int> > a(n, vector<int>(m, 0));;
    rep(i, n) {
        rep(j, m) {
            cin >> a[i][j];
        }
    }
    int res = 0;
    rep(i, n) {
        LL tmp = 0;
        rep(j, m) {
            tmp += a[i][j] * b[j];
        }
        if (tmp + c > 0) {
            res += 1;
        }
    }
    cout << res << endl;
    return 0;
}
