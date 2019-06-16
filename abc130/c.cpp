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
    LL w, h, x, y;
    cin >> w >> h >> x >> y;

    int flag = 0;
    if (2 * x == w and 2 * y == h) flag = 1;
    printf("%.9f %d\n", w * h / 2.0, flag);
    return 0;
}
