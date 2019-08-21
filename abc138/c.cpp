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
    vector<int> v(n);
    rep(i, n) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    double ans = v[0];
    rep(i, n - 1) {
        ans = (ans + v[i + 1]) / 2;
    }
    printf("%.7lf\n", ans);
    return 0;
}
