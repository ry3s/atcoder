#include <cstdio>
#include <climits>
#include <cassert>
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
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
using Data = pair<LL, vector<LL>>;

int main() {
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<LL> a(X), b(Y), c(Z);
    rep(i, X) {
        cin >> a[i];
    }
    rep(i, Y) {
        cin >> b[i];
    }
    rep(i, Z) {
        cin >> c[i];
    }
    sort(a.begin(), a.end(), greater<LL>());
    sort(b.begin(), b.end(), greater<LL>());
    sort(c.begin(), c.end(), greater<LL>());
    vector<LL> ab;
    rep(i, X) {
        rep(j, Y) {
            ab.push_back(a[i] + b[j]);
        }
    }
    sort(ab.begin(), ab.end(), greater<LL>());
    ab.resize(K);

    vector<LL> abc;
    rep(i, ab.size()) {
        rep(j, Z) {
            abc.push_back(ab[i] + c[j]);
        }
    }
    sort(abc.begin(), abc.end(), greater<LL>());

    rep(i, K) {
        cout << abc[i] << endl;
    }
    return 0;
}
