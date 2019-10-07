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
    int m; cin >> m;
    double x = m / 1000.0;
    if (x < 0.1) {
        cout << "00" << endl;
    } else if (x <= 5) {
        int ans = x * 10;
        if (ans / 10 == 0) {
            cout << 0 << ans << endl;
        } else {
            cout << ans << endl;
        }
    } else if (x <= 30) {
        cout << (int)x + 50 << endl;
    } else if (x <= 70) {
        int ans = (x - 30) / 5 + 80;
        cout << ans << endl;
    } else {
        cout << 89 << endl;
    }
}
