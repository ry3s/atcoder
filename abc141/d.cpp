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


const double EPS = 1e-9;
int main() {
    int n, m; cin >> n >> m;
    priority_queue<LL> que;
    rep(i, n) {
        LL a;
        cin >> a;
        que.push(a);
    }
    rep(i, m) if (not que.empty()){

        auto x = que.top(); que.pop();
        x /= 2;

        if (x < 0.9) {
            n--;
            continue;
        }

        que.push(x);
    }
    LL ans = 0;
    rep(i, n) {
        auto x = que.top(); que.pop();
        ans += x;
    }
    cout << ans << endl;
    return 0;
}
