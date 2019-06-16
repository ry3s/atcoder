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
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    rep(i, n) {
        cin >> v[i];
    }
    int d = 0;
    int cnt = 1;
    rep(i, n) {
        d += v[i];

        if (d > x) {
            break;
        }
        cnt++;
    }
    cout << min(n + 1, cnt) << endl;
    return 0;
}
