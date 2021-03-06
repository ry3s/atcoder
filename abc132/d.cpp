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
const int MAX_C = 2100;
LL com[MAX_C][MAX_C];
void calc_com() {
    memset(com, 0, sizeof(com));
    com[0][0] = 1;
    for (int i = 1; i < MAX_C; ++i) {
        com[i][0] = 1;
        for (int j = 1; j < MAX_C; ++j) {
            com[i][j] = (com[i-1][j-1] + com[i-1][j]) % MOD;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    calc_com();
    loop(i, 1, k + 1) {
        cout << (com[k - 1][i - 1] * com[n - k + 1][i]) % MOD << endl;
    }
    return 0;
}
