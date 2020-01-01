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

int main() {
    string s; cin >> s;
    int t; cin >> t;

    long long x = 0, y = 0, q = 0;

    for (const auto &c: s) {
        if (c == 'L') x--;
        else if (c == 'R') x++;
        else if (c == 'U') y++;
        else if (c == 'D') y--;
        else q++;
    }

    auto dist = abs(x) + abs(y);
    long long ans = 0;
    if (t == 1) {
        ans = dist + q;
    } else if (dist < q){
        ans = (q - dist) % 2;
    } else {
        ans = dist - q;
    }
    cout << ans << endl;
}
