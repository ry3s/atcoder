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
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;

int main() {
    int k; cin >> k;

    queue<int64_t> que;
    for (int i = 1; i <= 9; i++) {
        que.push(i);
    }

    int64_t ans;
    for (int i = 0; i < k; i++) {
        ans = que.front();
        que.pop();
        auto rem = ans % 10;
        if (rem != 0) {
            que.push(ans * 10 + rem - 1);
        }
        que.push(ans * 10 + rem);
        if (rem != 9) {
            que.push(ans * 10 + rem + 1);
        }
    }
    cout << ans << endl;
}
