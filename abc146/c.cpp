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
long long count_digit(long long num) {
    long long digit = 0;
    while (num != 0) {
        num /= 10;
        digit++;
    }
    return digit;
}
int main() {
    long long a, b, x; cin >> a >> b >> x;

    long long ok, ng;
    ok = 0;
    ng = 1e9 + 1;
    while (abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;

        auto temp = a * mid + b * count_digit(mid);

        if (temp <= x) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}
