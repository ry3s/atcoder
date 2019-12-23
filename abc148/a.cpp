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
    int a, b; cin >> a >> b;
    if ((a == 1 && b == 2) || (a == 2 && b == 1)) {
        cout << 3 << endl;
    } else if ((a == 2 && b == 3) || (a == 3 && b == 2)) {
        cout <<  1 << endl;
    } else {
        cout << 2 << endl;
    }
}
