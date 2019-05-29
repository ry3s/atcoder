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
    set<LL> st1;
    set<LL> st2;
    vector<pair<LL, LL> > v(n);
    rep(i, n) {
        LL a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }

    st1.insert(v[0].first);
    st2.insert(v[0].second);

    for (int i = 1; i < n; i++) {
        auto ab = v[i];
        LL a = ab.first;
        LL b = ab.second;

        if (st1.find(a) != st1.end()) {
            st1.insert(b);
        } else {
            st1.insert(a);
        }

        if (st2.find(a) != st2.end()) {
            st2.insert(b);
        } else {
            st2.insert(a);
        }


    }
    cout << max(st1.size(), st2.size()) << endl;
    return 0;
}
