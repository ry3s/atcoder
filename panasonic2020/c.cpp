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
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;

int main() {
    long double a, b, c; cin >> a >> b >> c;
    if (a + b + 2 * sqrt(a) * sqrt(b) < c) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
