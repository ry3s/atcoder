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
vector<LL> weights, values;
int n, w;
vector<vector<LL>>  dp(101, vector<LL>(101010, -1));


LL search(int num_item, LL weight) {
    LL res = 0;
    if (dp[num_item][weight] != -1) {
        return dp[num_item][weight];
    } else if (num_item == n) {
        return 0;
    } else if (weight < weights[num_item]) {
        res = search(num_item + 1, weight);
    } else {
        LL res1 = search(num_item + 1, weight);
        LL res2 = search(num_item + 1, weight - weights[num_item]) + values[num_item];
        res = max(res1, res2);
    }
    return dp[num_item][weight] = res;
}
int main() {
    cin >> n >> w;
    rep(i, n) {
        LL x, y;
        cin >> x >> y;
        weights.push_back(x);
        values.push_back(y);
    }

    cout << search(0, w) << endl;

}
