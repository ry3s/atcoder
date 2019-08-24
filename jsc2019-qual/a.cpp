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
    int m, d;
    cin >> m >> d;
    LL ans = 0;
    for (int i = 1; i <= m; i++) {

            for (int j = 1; j <= d; j++) {
                int d1 = j % 10;
                int d2 = j / 10;
                if (d1 >= 2 and d2 >= 2 and d1 * d2 == i) ans++;
            }

    }
    cout << ans << endl;
    return 0;
}
