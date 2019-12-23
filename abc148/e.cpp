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
    long long n; cin >> n;

    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    n /= 2;
    long long m = 5;
    long long ans = 0;
    while (n >= m) {
        ans += n / m;
        m *= 5;
    }
    cout << ans << endl;
}
