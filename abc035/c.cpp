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
    int n, q; cin >> n >> q;

    vector<int> a(n + 1, 0);
    rep(i, q) {
        int l, r; cin >> l >> r;
        --l, --r;
        a[l]++, a[r + 1]--; // [l, r)
    }

    vector<int> acc(n + 1, 0);
    for (int i = 0; i < n; i++) {
        acc[i + 1] = a[i] + acc[i];
    }

    rep(i, n) {
        if (acc[i + 1] % 2 == 0) {
            cout << '0';
        } else {
            cout << '1';
        }
    }
    cout << endl;

}
