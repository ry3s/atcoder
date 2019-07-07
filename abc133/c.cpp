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
    LL L, R;
    cin >> L >> R;
    LL ans = 2019;
    for (LL i = L; i <= L + 2019 * 2 - 1 and i <= R - 1; i++) {
        for (LL j = i + 1; j <= L + 2019 * 2 and j <= R; j++) {
            LL tmp = (i * j) % 2019;
            ans = min(ans, tmp);
        }

    }
    cout << ans << endl;
    return 0;
}
