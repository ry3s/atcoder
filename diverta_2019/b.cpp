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
    int r, g, b, n;
    cin >> r >> g >> b >> n;

    LL ans = 0;
    rep(red, n + 1) {
        rep(green, n + 1) {
            int blue = n - red * r - green * g;
            if (blue >= 0 and blue % b == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
