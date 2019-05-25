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
    vector<pair<LL, LL> > gates;
    rep(i, m) {
        LL l, r;
        cin >> l >> r;
        gates.push_back(make_pair(l, r));
    }
    LL max_left = 0;
    LL min_right = 1e9;
    rep(i, m) {
        auto lr = gates[i];
        max_left = max(max_left, lr.first);
        min_right = min(min_right, lr.second);
    }
    if (min_right - max_left + 1 >= 0) {
        cout << min_right - max_left + 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
