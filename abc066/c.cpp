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
    deque<int> dq;

    rep(i, n) {
        if (i % 2 == 0) {
            dq.push_back(a[i]);
        } else {
            dq.push_front(a[i]);
        }
    }
    if (n % 2 != 0) reverse(dq.begin(), dq.end());
    for (auto &e: dq) {
        cout << e << " ";
    }
    cout << endl;
}
