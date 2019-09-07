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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int num_lr = 0;
    rep(i, n - 1) {
        if (s[i] == 'R' and s[i + 1] == 'L') num_lr++;
    }
    int x = num_lr;
    int y = num_lr - 1;
    y += (s[0] == 'R' ? 0 : 1);
    y += (s[n - 1] == 'L' ? 0 : 1);
    x -= k;
    y -= k;
    if (x <= 0 and y <= 0) {
        cout << n - 1 << endl;
    } else {
        cout << n - 1 - x - y << endl;
    }
    return 0;
}
