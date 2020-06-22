#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;

int main() {
    int n; cin >> n;
    vector<int64_t> arr(n);
    map<int64_t, int64_t> mp;
    rep(i, n) {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    int64_t sm = 0;
    rep(i, n) {
        sm += arr[i];
    }

    int64_t q; cin >> q;
    rep(i, q) {
        int64_t b, c; cin >> b >> c;
        int64_t cnt = mp[b];
        mp[b] -= cnt;
        mp[c] += cnt;
        sm = sm + (c - b) * cnt;
        cout << sm << endl;
    }
}
