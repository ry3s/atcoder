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
    long long x; cin >> x;

    auto ans = (x / 11) * 2;
    auto rem = x % 11;

    if (rem > 0) {
        if (rem > 6) {
            ans += 2;
        } else {
            ans += 1;
        }
    }

    cout << ans << endl;

}
