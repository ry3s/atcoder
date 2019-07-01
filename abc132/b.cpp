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

    vector<int> p(n);
    rep(i, n) {
        cin >> p[i];
    }
    int ans = 0;
    rep(i, n - 2) {
        if (p[i + 1] < max(p[i], p[i + 2]) and p[i + 1] > min(p[i], p[i + 2]))
            ans++;
    }
    cout << ans << endl;
    return 0;
}
