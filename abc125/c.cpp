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
#include <numeric>
#include <bitset>
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
unsigned gcd(unsigned a, unsigned b) {
  if(a < b) gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main() {
    LL n;
    cin >> n;
    vector<LL> a(n);
    rep(i, n) {
        cin >> a[i];
    }


    sort(a.begin(), a.end());
    LL diff_min = 21412342141234132;
    LL min_index = -1;
    rep(i, n - 1) {
        LL diff = a[i + 1] - a[i];
        if (diff < diff_min) {
            diff_min = diff;
            min_index = i + 1;
        }
    }
    LL res = min_index == 0 ? a[1] : a[0];
    rep(i, n) {
        if (i == min_index) continue;
        res = gcd(res, a[i]);
        //cout << res << endl;
    }
    cout << res << endl;

    // rep(i, n) {
    //     LL res_gcd = i == 0 ? a[1] : a[0];
    //     rep(j, n) {
    //         if (i == j) {
    //             continue;
    //         }
    //         res_gcd = gcd(res_gcd, a[j]);
    //     }
    //     res = max(res, res_gcd);
    // }
    // cout << res << endl;
    return 0;
}
