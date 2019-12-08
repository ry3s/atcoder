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
set<int> digits(int num) {
    set<int> ret;
    while (num != 0) {
        int tmp = num % 10;
        ret.insert(tmp);
        num /= 10;
    }
    return ret;
}

int main() {
    int n, k; cin >> n >> k;
    set<int> d;
    rep(i, k) {
        int x; cin >> x;
        d.insert(x);
    }

    for (int i = n; i < 1000'000; i++) {
        set<int> result;
        auto ds = digits(i);
        set_intersection(d.begin(), d.end(),
                         ds.begin(), ds.end(),
                         inserter(result, result.end()));
        if (result.empty()) {
            cout << i << endl;
            break;
        }
    }
}
