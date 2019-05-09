#include <cstdio>
#include <climits>
#include <cassert>
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
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    ULL a, b;
    cin >> a >> b;
    ULL res = 0;
    if (a == b) {
        cout << a << endl;
    } else if ((a - b) % 2 == 0) {
        assert(false);
        res = (a ^ b) - 1;
        cout << res << endl;
    } else {
        res = a ^ b;
        cout << res << endl;
    }
    // for (ULL i = a + 1; i <= b; i++) {
    //     res = res ^ i;
    // }
    // cout << res << endl;
    return 0;
}
