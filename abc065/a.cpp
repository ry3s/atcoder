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
    long long x, a, b; cin >> x >> a >> b;
    LL d = b - a;
    if (d <= 0) {
        cout << "delicious" << endl;
    } else if (d <= x) {
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }
}
