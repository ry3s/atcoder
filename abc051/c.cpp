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
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;

    int dx = tx - sx, dy = ty - sy;

    string res = "";

    rep(i, dx) res += "R";
    rep(i, dy) res += "U";
    rep(i, dx) res += "L";
    rep(i, dy) res += "D";

    res += "D";
    rep(i, dx + 1) res += "R";
    rep(i, dy + 1) res += "U";
    res += "L";
    res += "U";
    rep(i, dx + 1) res += "L";
    rep(i, dy + 1) res += "D";
    res += "R";

    cout << res << endl;
}
