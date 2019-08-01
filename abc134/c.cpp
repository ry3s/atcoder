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
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vector<int> max_left(n + 1);
    vector<int> max_right(n + 1);
    max_left[0] = -1000000;
    rep(i, n) {
        max_left[i + 1] = max(a[i], max_left[i]);
    }
    max_right[n] = -1000000;
    rep(i, n) {
        max_right[i + 1] = max(a[n - 1 - i], max_right[i]);
    }
    rep(i, n) {
        cout << max(max_left[i], max_right[n - i - 1])<< endl;;
    }


}
