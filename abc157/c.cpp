#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iterator>
#include <sstream>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
int n, m;
vector<int> s, c;

bool check(string str) {
    if ((int)str.size() != n) return false;
    rep(i, m) {
        if (str[s[i]] != (char)(c[i] + '0')) return false;
    }
    return true;
}
string solve() {
    for (int i = 0; i <= 999; i++) {
        stringstream iss;
        iss << i;
        string str = iss.str();
        if (check(str)) return str;
    }
    return "-1";
}
int main() {
   cin >> n >> m;
   s.resize(m), c.resize(m);

   rep(i, m) cin >> s[i] >> c[i], --s[i];
   cout << solve() << endl;
}
