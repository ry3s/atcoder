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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int n;
    cin >> n;
    vector<pair<LL, LL> > v(n);
    rep(i, n) {
        LL x, y;
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }
    rep(i, n) {
        auto xy = v[i];
        LL x = xy.first;
        LL y = xy.second;
        cout << x * y << endl;
    }
    return 0;
}
