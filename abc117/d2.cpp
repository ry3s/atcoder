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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;

int main() {
    LL n, k; cin >> n >> k;
    vector<LL> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    LL res = 0;
    for (int d = 60; d >= -1; d--) {
        if (d != -1 and not (k & (1LL << d))) continue;

        LL tmp = 0;
        for (int e = 60; e >= 0; e--) {
            LL mask = (1LL << e);
            int num = 0;
            rep(i, n) {
                if (a[i] & mask) num++;
            }

            if (e > d) {
                if (k & mask) tmp += mask * (n - num);
                else tmp += mask * num;
            } else if (e == d) {
                tmp += mask * num;
            } else {
                tmp += mask * max((LL)num, n - num);
            }
        }
        res = max(res, tmp);
    }
    cout << res << endl;
}
