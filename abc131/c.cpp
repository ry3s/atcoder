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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

LL gcd(LL m, LL n) {
    if (n ==  0) return abs(m);
    else return gcd(n, m % n);
}
LL calc(LL n, LL c, LL d) {
    LL g = gcd(c, d);
    LL l = c / g * d;
    return n - n / c - n / d + n / l;
}
int main() {
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << calc(b, c, d) - calc(a - 1, c, d) << endl;
    return 0;
}
