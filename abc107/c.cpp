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

    vector<LL> v(n);
    rep(i, n) {
        cin >> v[i];
    }
    LL ans = LLONG_MAX;
    rep(i, n - k + 1) {
        LL l = i;
        LL r = i + k - 1;
        ans = min (ans, min(abs(v[l]) + abs(v[r] - v[l])
                            , abs(v[r]) + abs(v[r] - v[l])));
    }
    cout << ans << endl;
    return 0;
}
