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

int main() {
    int a, b;
    cin >> a >> b;

    if (a >= 13) {
        cout << b << endl;
    } else if (a >= 6) {
        cout << b / 2 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
