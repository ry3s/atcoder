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
    int a, b, c, d; cin >> a >> b >> c >> d;

    int ans = 0;
    if (c < a) {
        if (d < b) ans = d - a;
        else ans = b - a;
    } else {
        if (d < b) ans = d - c;
        else ans = b - c;
    }
    cout << (ans > 0 ? ans : 0) << endl;
}
