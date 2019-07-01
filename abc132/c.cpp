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
    vector<int> d(n);
    rep(i, n) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    int mid_left = d[n / 2 - 1];
    int mid_right = d[n / 2];
    if (mid_left == mid_right) {
        cout << 0 << endl;
    } else {
        cout << mid_right - mid_left << endl;
    }
    return 0;
}
