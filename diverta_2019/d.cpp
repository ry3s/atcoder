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

    LL n;
    cin >> n;

    LL ans = 0;

    for (LL r = 1; r * r <= n; r++) {
        if ((n - r) % r == 0
            and (n - r) / r > r) {
            ans += (n - r) / r;
            }
    }
    cout << ans << endl;
    return 0;

}
