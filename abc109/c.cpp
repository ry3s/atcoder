#include <cstdio>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <bitset>
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define mod 1000000007
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

LL gcd(LL m, LL n) {
    if (n == 0) return abs(m);
    else return gcd(n, m % n);
}

int main() {
    LL n, x;
    cin >> n >> x;

    vector<LL> city(n);
    rep(i, n) {
        cin >> city[i];
    }
    vector<LL> dist(n);
    rep(i, n) {
        dist[i] = abs(city[i] - x);
    }

    LL ans = dist[0];
    rep(i, n) {
        ans = gcd(ans, dist[i]);
    }
    cout << ans << endl;

}
