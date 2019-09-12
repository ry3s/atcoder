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
    int n, k; cin >> n >> k;
    auto cmp = [](auto a, auto b) { return a.first > b.first; };
    priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, decltype(cmp)> que(cmp);

    rep(i, n) {
        LL a, b; cin >> a >> b;
        que.push(make_pair(a, b));
    }
    LL ans = 0;
    rep(i, k) {
        auto ab = que.top();
        que.pop();
        ans += ab.first;
        que.push(make_pair(ab.first + ab.second, ab.second));
    }
    cout << ans << endl;
    return 0;
}
