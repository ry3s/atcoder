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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
using ULL = unsigned long long;

int main() {
    int n; cin >> n;
    vector<pair<double, string>> v(n);
    rep(i, n) {
        double x;
        string u;
        cin >> x >> u;
        v[i] = make_pair(x, u);
    }
    double ans = 0.;
    for (auto xu : v) {
        if (xu.second == "JPY") {
            ans += xu.first;
        } else {
            ans += xu.first * 380000.0;
        }
    }
    cout << ans << endl;
    return 0;
}
