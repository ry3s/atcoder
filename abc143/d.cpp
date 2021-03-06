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
    vector<int> l(n);
    rep(i, n) scanf("%d", &l[i]);

    sort(l.begin(), l.end());
    LL ans = 0;
    rep(i, n) {
        loop(j, i + 1, n) {
            int k = lower_bound(l.begin(), l.end(), l[i] + l[j]) - l.begin();
            ans += max(k - (j + 1), 0);
        }
    }
    printf("%lld\n", ans);
}
