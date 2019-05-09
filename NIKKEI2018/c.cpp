#include <cstdio>
#include <climits>
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
#define mod 1000000007
using namespace std;
typedef long long int LL;

int main() {
    int n;
    cin >> n;

    vector<LL> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }

    vector<pair<LL, int> > diff(n);
    rep(i, n) {
        diff[i] = make_pair(a[i] - b[i], i);
    }

    sort(diff.begin(), diff.end(), [](pair<LL, int> &a, pair<LL, int> &b) {
                                       if (a.first == b.first) {
                                           return a.second > b.second;
                                       } else {
                                           return a.first < b.first;
                                       }
                                   });
    LL ans = 0;
    rep(i, n) {
        if (i % 2 == 0) {
            ans += a[diff[i].second];
        } else {
            ans -= b[diff[i].second];
        }
    }
    cout << ans << endl;
    return 0;
}
