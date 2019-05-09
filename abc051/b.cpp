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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int k, s;
    cin >> k >> s;

    LL res = 0;

    rep(x, k + 1) {
        rep(y, k + 1) {
            int z = s - x - y;
            if (z >= 0 && z <= k) res++;
        }
    }

    cout << res << endl;
    return 0;
}
