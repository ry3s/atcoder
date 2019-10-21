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
#include <bitset>
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i], --a[i];

    int idx = 0;
    int cnt = 0;
    rep(i, n) {
        idx = a[idx];
        ++cnt;
        if (idx == 1) {
            cout << cnt << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
