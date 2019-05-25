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
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n);
    vector<pair<LL, LL> > v(m);


    rep(i, n) {
        cin >> a[i];
    }
    rep(i, m) {
        LL b, c;
        cin >> b >> c;
        v[i] = make_pair(b, c);
    }
    sort(a.begin(), a.end());
    sort(v.begin(), v.end(), [](const auto &a, const auto &b){
                                 return a.second > b.second;
                             });

    vector<LL> ans(n, 0);
    LL cnt = 0;
    rep(i, m) {
        LL num_card = 0;
        while (num_card < v[i].first and cnt < n) {
            ans[cnt] = v[i].second;
            num_card++;
            cnt++;
        }
    }
    // rep(i, n) {
    //     cout << a[i] << ' ' << ans[i] << endl;
    // }

    LL index = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (ans[i] < a[index]) {
            ans[i] = a[index];
            index--;
        }
    }
    LL sum = 0;
    rep(i, n) {
        sum += ans[i];
    }
    cout << sum << endl;
    return 0;
}
