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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;

int main() {
    int d;
    cin >> d;
    if (d == 25) {
        cout << "Christmas" << endl;
    } else if (d == 24) {
        cout << "Christmas Eve" << endl;
    } else if (d == 23) {
        cout << "Christmas Eve Eve" << endl;
    } else {
        cout << "Christmas Eve Eve Eve" << endl;
    }
    return 0;
}
