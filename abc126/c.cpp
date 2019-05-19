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
    LL n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << 1.000000000000 << endl;
        return 0;
    }
    if (n == 1) {
        LL x = ceil(log2(k));
        double ans =  (1./n) * (1.0 / pow(2, x));
        printf("%.12f\n", ans);
        return 0;
    }
    double ans = 0.;
    for (LL i = 1; i <= n; i++) {
        if (i >= k) {
            ans += 1.0/n;
            continue;
        }
        LL x = ceil(log2(k) - log2(i));
        ans += (1.0/n) * (1.0 / pow(2, x));
    }
    printf("%.12f\n", ans);
    return 0;
}
