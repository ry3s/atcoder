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
const LL MOD = 1e9 + 7;

map<int, int> prime_factorize(int n) {
    map<int, int> prime_factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++prime_factors[i];
            n /= i;
        }
    }
    if (n != 1) prime_factors[n] = 1;
    return prime_factors;
}
int main() {
    int n; cin >> n;

    map<LL, int> factors;
    loop(i, 1, n + 1) {
        for (auto it : prime_factorize(i)) {
            int p, cnt; tie(p, cnt) = it;
            factors[p] += cnt;
        }
    }
    LL ans = 1;
    for (auto it : factors) {
        int cnt = it.second;
        ans = ans * (1 + cnt) % MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}
