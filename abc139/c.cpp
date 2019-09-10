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
    vector<LL> h(n);
    rep(i, n) {
        cin >> h[i];
    }
    vector<int> ans(1, 0);
    LL cur = h[0];
    rep(i, n - 1) {
        if (h[i + 1] <= cur) {
            cur = h[i + 1];
            ans.back() += 1;
        } else {
            cur = h[i + 1];
            ans.push_back(0);
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    cout << ans[0] << endl;
}
