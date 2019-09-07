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

const int contests[] = { 111, 222, 333, 444, 555, 666, 777, 888, 999 };
int main() {
    int n; cin >> n;
    rep(i, 9) {
        if (n <= contests[i]) {
            cout << contests[i] << endl;
            return 0;
        }
    }
    return 0;
}
