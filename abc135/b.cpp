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
    auto p2 = p;
    sort(p2.begin(), p2.end());
    LL cnt = 0;
    rep(i, n) {
        if (p[i] != p2[i]) cnt++;
    }
    if (cnt <= 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
