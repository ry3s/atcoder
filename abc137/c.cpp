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
    map<string, LL> ans;
    rep(i, n) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        ans[s]++;
    }
    LL sum = 0;
    for (auto e : ans) {
        LL tmp = e.second * (e.second - 1) / 2;
        sum += tmp;
    }
    cout << sum << endl;

    return 0;
}
