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
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    int x = x2 - x1;
    int y = y2 - y1;
    cout << x2 - y << " " << y2 + x << " ";
    cout << x1 - y << " " << y1 + x << endl;
}
