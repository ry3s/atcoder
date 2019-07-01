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
const LL MOD = 1e9 + 7;

LL fact(LL n) {
    if (n == 1) return 1;
    else return (n % MOD) * (fact(n - 1) % MOD);
}


template<class T> struct Partition {
    vector<vector<T> > P;
    constexpr Partition(int MAX) noexcept : P(MAX, vector<T>(MAX, 0)) {
        for (int k = 0; k < MAX; ++k) P[0][k] = 1;
        for (int n = 1; n < MAX; ++n) {
            for (int k = 1; k < MAX; ++k) {
                P[n][k] = P[n][k-1] + (n-k >= 0 ? P[n-k][k] : 0);
            }
        }
    }
    constexpr T get(int n, int k) {
        if (n < 0 || k < 0) return 0;
        return P[n][k];
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    LL red = n - k;
    Partition<LL> pt(k + 1);
    LL sum = 0;
    for (int i = 1; i < k + 1; i++) {
        LL x = k % i == 0 ? fact(i) : 1;
        LL junretsu = fact(i + red) / (x * fact(red));
        cout << junretsu - sum << endl;
        sum += junretsu;
    }
    return 0;
}
