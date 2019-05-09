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
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    LL n, m;
    cin >> n >> m;

    vector<LL> v(m);
    rep(i, m) {
        cin >> v[i];
    }

    if (n >= m) {
        cout << 0 << endl;
        return 0;
    }
    sort(v.begin(), v.end());
    vector<LL> diff(m - 1);

    rep(i, m - 1) {
        diff[i] = v[i + 1] - v[i];
    }
    sort(diff.begin(), diff.end(), greater<LL>());
    // rep(i, m - 1){
    //     cout << diff[i] << endl;
    // }

    LL sum = 0;
    for (int i = n - 1; i < m - 1; i++) {
        sum += diff[i];
    }
    cout << sum << endl;
    return 0;
}
