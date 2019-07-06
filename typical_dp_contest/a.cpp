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
    vector<int> p(n);
    rep(i, n) {
        cin >> p[i];
    }
    vector<bool> dp(100 * 100 + 1);
    dp[0] = true;
    rep(i, n) {
        for (int j = 100 * 100 - p[i]; j >= 0; j--) {
            dp[j + p[i]] = (dp[j + p[i]] | dp[j]);
        }
    }
    cout << count(dp.begin(), dp.end(), true) << endl;
}
