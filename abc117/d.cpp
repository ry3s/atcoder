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
#include <cassert>

#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

LL pow2(LL n)
{
    if(n < 0)
        return 0;
    if(n == 1)
        return 1;

    return (LL)pow(2.0, (floor(log2(n - 1)) + 1.0));
}
int main() {
    ULL n, k;
    cin >> n >> k;

    vector<ULL> v(n);
    ULL maxi = 0;
    rep(i, n) {
        cin >> v[i];
        if (maxi < v[i]) {
            maxi = v[i];
        }
    }
    ULL flag = 0;
    rep(i, n) {
        flag ^= v[i];
    }

    if (flag == 0) {
        flag = pow2(maxi);
        // cout << "?"<< endl;
        // cout << maxi << endl;
    }
    //cout <<"!!!" <<flag << endl;
    if (flag < k) {
        ULL sum = 0;
        rep(i, n) {
            sum += v[i] ^ flag;
        }
        cout << sum << endl;
    } else {
//        assert(false);
        ULL tmp = (flag & k) | k;
        ULL sum = 0;
        rep(i, n) {
            sum += v[i] ^ tmp;
        }
        cout << sum << endl;
    }
    // for (ULL i = 0; i < (ULL)k; i++) {
    //     LL sum = 0;
    //     for (ULL j = 0; j < (ULL)n; j++) {
    //         sum += v[j] ^ i;
    //     }
    //     cout << i << " " << sum << endl;
    // }
    return 0;
}
