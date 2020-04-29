#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
int64_t inline gcd(int64_t a, int64_t b) {
    if (a < b) return gcd(b, a);

    int64_t r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}
int main() {
    int k; cin >> k;

    int64_t ans = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = i; j <= k; j++) {
            for (int l = j; l <= k; l++) {
                if (i == j && j == l) {
                    ans +=  gcd(i, gcd(j, l));
                } else if (i == j || j == l || l == i){
                    ans += 3 * gcd(i, gcd(j, l));
                } else {
                    ans += 6 *  gcd(i, gcd(j, l));
                }

            }
        }
    }
    cout << ans << endl;
}
