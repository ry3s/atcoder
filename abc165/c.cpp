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
vector<vector<int>> perm;
int n, m, q;
void f(int i, int cur, vector<int> acc) {
    if (i == n) {
        perm.push_back(acc);
    } else {
        acc.push_back(cur);
        for (int j = cur; j <= m; j++) {
            f(i + 1, j, acc);
        }
    }
}
int main() {
    cin >> n >> m >> q;
    perm.clear();
    vector<int> as(q), bs(q), cs(q), ds(q);
    rep(i, q) cin >> as[i] >> bs[i] >> cs[i] >> ds[i];

    f(0, 1, vector<int>());

    int64_t maxi = 0;
    for (auto v: perm) {
        int64_t sum = 0;
        rep(i, q) {
            if (v[bs[i] - 1] - v[as[i] - 1] == cs[i]) {
                sum += ds[i];
            }
        }
        maxi = max(maxi, sum);
    }
    cout << maxi << endl;

    // for (auto v: perm) {
    //     for (auto x: v) {
    //         cout << x  << " ";
    //     }
    //     cout << endl;
    // }
}
