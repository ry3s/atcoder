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
    int n, k; cin >> n >> k;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];

    vector<long long> acc(n + 1, 0);
    acc[0] = 0;
    rep(i, n) {
        acc[i + 1] = acc[i] + a[i];
    }

    long long ans = 0;
    rep(i, n - k + 1) {
        ans += acc[i + k] - acc[i];
    }

    cout << ans << endl;
}
