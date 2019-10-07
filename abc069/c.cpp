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
    vector<LL> a(n);
    rep(i, n) cin >> a[i];

    int cnt4 = 0, cnt2 = 0, cnt = 0;
    for (auto &x: a) {
        if (x % 4 == 0) ++cnt4;
        else if (x % 2 == 0) ++cnt2;
        else ++cnt;
    }

    if ((cnt2 == 0 and cnt4 + 1 >= cnt) or cnt4 >= cnt) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
