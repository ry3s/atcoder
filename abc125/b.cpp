#include <cstdio>
#include <climits>
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
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int n;
    cin >> n;
    vector<int> v(n), c(n);
    rep(i, n) {
        cin >> v[i];
    }
    rep(i, n) {
        cin >> c[i];
    }

    int res = -141341234;
    for (ULL bit = 0; bit < (1 << n); bit++) {
        int x = 0;
        int y = 0;
        rep(i, n) {
            if (bit & (1 << i)) {
                x += v[i];
                y += c[i];
            }
        }
        res = max(res, x - y);
    }
    cout << res << endl;
    return 0;
}
