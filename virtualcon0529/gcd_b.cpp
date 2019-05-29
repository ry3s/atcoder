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
LL e_gcd(LL a, LL b) {
  if(a < b) return e_gcd(b, a);
  LL r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main() {
    int n;
    cin >> n;
    vector<pair<LL, LL> > v;
    rep(i, n) {
        LL a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    int ans1 = v[0].first;
    int ans2 = v[0].second;

    for (int i = 1; i < n; i++) {
        auto ab = v[i];
        LL a = ab.first;
        LL b = ab.second;
        LL ans1a = e_gcd(ans1, a);
        LL ans1b = e_gcd(ans1, b);
        LL ans2a = e_gcd(ans2, a);
        LL ans2b = e_gcd(ans2, b);

        if (ans1a > ans1b) {
            ans1 = ans1a;
        } else {
            ans1 = ans1b;
        }

        if (ans2a > ans2b) {
            ans2 = ans2a;
        } else {
            ans2 = ans2b;
        }


    }
    cout << max(ans1, ans2) << endl;
    return 0;
}
