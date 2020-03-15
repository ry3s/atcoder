#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
vector<int64_t> memo(1000001, 0);
const int64_t mod = 10007;

void tribonacci(int64_t n) {
    memo[0] = 0;
    memo[1] = 0;
    memo[2] = 1;
    for (int64_t i = 0; i < n + 1; i++) {
        memo[i + 3] =(memo[i + 2] + memo[i + 1] + memo[i]) % mod;
    }
}
int main() {
    int64_t n; cin >> n;

    tribonacci(n);
    cout << memo[n - 1] % mod << endl;
}
