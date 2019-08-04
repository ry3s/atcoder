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
    int n;
    cin >> n;
    vector<LL> h(n);
    rep(i, n) {
        cin >> h[i];
    }
    if (n == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    bool ok = true;
    for (int i = n - 1; i >= 1; i--) {
        LL current = h[i];
        LL prev = h[i - 1];
        if (current >= prev) {
            continue;
        } else if (current == prev - 1) {
            h[i - 1] -= 1;
        } else {
            ok = false;
        }
    }
    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
