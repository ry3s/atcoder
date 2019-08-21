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
    int a, b;
    cin >> a >> b;
    if (a > b) {
        if (a - 1 > b) {
            cout << a + a - 1 << endl;
        } else {
            cout << a + b << endl;
        }
    } else {
        if (b - 1 > a) {
            cout << b + b - 1 << endl;
        } else {
            cout << b + a << endl;
        }
    }

    return 0;
}
