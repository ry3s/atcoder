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
    string s; cin >> s;

    bool ok = true;
    for (int i = 1; i <= 2; i++) {
        if (s[i] == s[0]);
        else ok = false;
    }
    if (ok) {
        cout << "Yes" << endl;
        return 0;
    }
    ok = true;
    for (int i = 2; i <= 3; i++) {
        if (s[i] == s[1]);
        else ok = false;
    }
    if (ok) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
