#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <bitset>
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
using ULL = unsigned long long;

int main() {
    int a, b; cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++) {
        int digit = i;
        int d1 = digit % 10; digit /= 10;
        int d2 = digit % 10; digit /= 10;
        int d3 = digit % 10; digit /= 10;
        int d4 = digit % 10; digit /= 10;
        int d5 = digit % 10;
        if (d1 == d5 and d2 == d4) ans++;
    }
    cout << ans << endl;
}
