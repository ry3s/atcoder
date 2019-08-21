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
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> v;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    priority_queue<int> que;
    LL ans = 0;
    for (int i = 0; i <= m; i++) {
        for (auto x :v[i]) {
            que.push(x);
        }

        if (que.empty()) continue;
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
}
