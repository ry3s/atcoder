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
    const double PI=3.141592653589;

    int a, b, x; cin >> a >> b >> x;

    double total = a * a * b;
    double diff = total - x;
    double ans = 0;
    if (diff < x) {
        double ans_rad = atan((2.0 * diff) / (a * a * a));
        ans = (ans_rad * 180) / PI;
    } else {
        double rad = atan( (2.0 * x) / (a * b * b));
        double deg = (rad * 180) / PI;
        ans = 90 - deg;
    }
    printf("%.8f\n", ans);
    return 0;
}
