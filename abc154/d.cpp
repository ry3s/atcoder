#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
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
    int n, k; cin >> n >> k;
    vector<long long> p(n);
    rep(i, n) cin >> p[i], ++p[i];

    vector<long long> s(n + 1, 0);
    rep(i, n) s[i + 1] = s[i] + p[i];

    long long res = 0;
    for (int i = 0; i + k <= n; i++) {
        res = max(res, s[i + k] - s[i]);
    }
    cout << fixed << setprecision(10)
         << static_cast<double>(res) / 2 << endl;
}
