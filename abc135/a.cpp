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
    LL a, b;
    cin >> a >> b;
    double k = ((b * b)  - (a * a)) / (double)(2 * (b - a));
    if (ceil(k) == floor(k)) {
        cout << (LL)k << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
