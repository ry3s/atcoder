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
    int n; LL k; int q; cin >> n >> k >> q;
    map<int, int> m;
    rep(i, q) {
        int a; cin >> a;
        a--;
        m[a]++;
    }
    vector<int> human(n, k);
    rep(i, n) {
        human[i] = human[i] - q + m[i];
    }
    rep(i, n) {
        if (human[i] <= 0) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }

    }
    return 0;
}
