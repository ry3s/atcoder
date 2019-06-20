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

void solve(int n) {
    vector<LL> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    LL sum = 0;
    rep(i, n) {
        sum += a[i];
    }

    LL ans = 0;
    rep(i, n) {
        if (a[i] * n <= sum) {
            ans++;
        }
    }
    cout << ans << endl;
}
int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        solve(n);
    }

    return 0;
}
