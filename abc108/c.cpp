#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <bitset>
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(val) cout << "!!!" << #val << ": " << val << endl
#define mod 1000000007
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    LL n, k;
    cin >> n >> k;

    // LL x = k / (2 * n);
    LL cnt = 0;
    LL cnt2 = 0;
    if (k % 2 != 0) {
        for (LL i = 1; i <= n; i++) {
            if (i % k == 0) cnt++;
        }
    } else {
        for (LL i = 1; i <= n; i++) {
            if (i % k == 0) cnt++;
            if ((i % k) == (k / 2)) cnt2++;
        }
    }

    cout << cnt * cnt * cnt  + cnt2 * cnt2 * cnt2 << endl;
    return 0;
}
