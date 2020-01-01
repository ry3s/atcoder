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
    vector<long long> a(n, 0);

    rep(i, q) {
        int l, r;
        long long t;
        cin >> l >> r >> t;
        --l, --r;
        for (int j = l; j <= r; j++) {
            a[j] = t;
        }
    }
    for (const auto& x: a) {
        cout << x << endl;
    }
}
