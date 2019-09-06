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
#include <numeric>
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;

int main() {
    int n; cin >> n;
    vector<int> p(n);
    rep(i, n) {
        cin >> p[i];
    }
    sort(p.begin(), p.end(), greater<int>());
    LL ans = p[0] / 2 + accumulate(p.begin() + 1, p.end(), 0,
                               [](int acc, int i) {
                                   return acc + i;
                                       });
    cout << ans << endl;
}
