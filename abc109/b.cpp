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
    int n; cin >> n;
    set<string> st;
    bool ok = true;
    string s1; cin >> s1;
    st.insert(s1);
    char last = s1.back();
    rep(i, n - 1) {
        string s; cin >> s;
        // debug(last);
        if (st.find(s) != st.end()) ok = false;
        if (s.front() != last) ok = false;
        st.insert(s);
        last = s.back();
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
