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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;

int main() {
    int n; cin >> n;
    map<string, int> mp;
    rep(i, n) {
        string s; cin >> s;
        mp[s]++;
    }
    int m; cin >> m;
    rep(i, m) {
        string t; cin >> t;
        mp[t]--;
    }
    int maxi = 0;
    for (auto e : mp) {
        maxi = max(maxi, e.second);
    }
    cout << maxi << endl;
}
