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
    int h1, h2, w1, w2;
    cin >> h1 >> w1 >> h2 >> w2;

    if (h1 == h2
        || h1 == w2
        || w1 == h2
        || w1 == w2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}