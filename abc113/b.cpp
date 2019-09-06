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
    int n; cin >> n;
    int t, a; cin >> t >> a;
    vector<int> h(n);
    rep(i, n) {
        cin >> h[i];
    }

    double mini = 1e9 + 1.0;
    int ans = 0;
    rep(i, n) {
        double temperature = t - h[i] * 0.006;
        if (mini > abs(temperature - a)) {
            mini = abs(temperature - a);
            ans = i + 1;
        }
    }
    cout << ans << endl;
}
