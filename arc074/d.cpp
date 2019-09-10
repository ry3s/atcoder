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
    vector<LL> a(3 * n);
    rep(i, 3 * n) {
        cin >> a[i];
    }

    vector<LL> left_sums(n * 2 + 1, 0);
    priority_queue<LL, vector<LL>, greater<LL>> que_left;
    rep(i, n) {
        left_sums[i + 1] = left_sums[i] + a[i];
        que_left.push(a[i]);
    }
    loop(i, n, n * 2) {
        LL mini = que_left.top();
        if (a[i] > mini) {
            left_sums[i + 1] = left_sums[i] - mini + a[i];
            que_left.pop();
            que_left.push(a[i]);
        } else {
            left_sums[i + 1] = left_sums[i];
        }
    }

    vector<LL> right_sums(n * 2 + 1, 0);
    priority_queue<LL> que_right;
    rep(i, n) {
        right_sums[i + 1] = right_sums[i] + a[n * 3 - 1 - i];
        que_right.push(a[n * 3 - 1 -i]);
    }
    loop(i, n, n * 2) {
        LL maxi = que_right.top();
        if (a[n * 3 - 1 - i] < maxi) {
            right_sums[i + 1] = right_sums[i] - maxi + a[n * 3 - 1 - i];
            que_right.pop();
            que_right.push(a[n * 3 - 1 - i]);
        } else {
            right_sums[i + 1] = right_sums[i];
        }
    }

    LL res = -9223372036854775808LL;
    loop(i, n, n * 2 + 1) {
        res = max(res, left_sums[i] - right_sums[n * 3 - i]);
    }
    cout << res << endl;
    return 0;
}
