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
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<int> xs(n);
    vector<int> ys(m);
    rep(i, n) {
        cin >> xs[i];
    }
    rep(i, m) {
        cin >> ys[i];
    }
    xs.push_back(x); ys.push_back(y);
    sort(xs.begin(), xs.end(), greater<int>());
    sort(ys.begin(), ys.end());

    if (ys[0] - xs[0] >= 1) {
        cout << "No War" << endl;
    } else {
        cout << "War" << endl;
    }
    return 0;
}
