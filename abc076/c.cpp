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
#include <bitset>
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;

int main() {
    string s, t; cin >> s >> t;

    int n = s.length();
    int m = t.length();

    set<string> ans;

    for (int r = n; r >= m; r--) {
        int l = r - m;

        bool ok = true;

        rep(i, m) if (s[l + i] != '?' and s[l + i] != t[i]) ok = false;

        if (ok) {
            string tmp;
            rep(i, n) tmp += s[i];
            rep(i, m) tmp[l + i] = t[i];
            rep(i, n) if (tmp[i] == '?') tmp[i] = 'a';
            ans.insert(tmp);
        }
    }

    if (ans.empty()) {
        cout << "UNRESTORABLE" << endl;
    } else {
        cout << *(ans.begin()) << endl;
    }

}
