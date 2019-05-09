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

    vector<int> t(n);
    rep(i, n) {
        cin >> t[i];
    }

    int res = 1e6;
    for (int bit = 0; bit < (1 << n); bit++) {
        int time1 = 0;
        int time2 = 0;

        rep(i, n) {
            if (bit & (1 << i)) {
                time1 += t[i];
            } else {
                time2 += t[i];
            }
        }

        res = min(res, max(time1, time2));
    }
    cout << res << endl;
    return 0;
}
