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
    vector<LL> h(n);
    rep(i, n) {
        cin >> h[i];
    }
    int cnt = 0;
    int pre_max = 0;
    for (int height : h) {
        if (height >= pre_max) cnt++;
        pre_max = max(height, pre_max);
    }
    cout << cnt << endl;
    return 0;
}
