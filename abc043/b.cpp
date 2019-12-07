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

    string ans = "";
    for (char c: s) {
        if (c == '0') {
            ans += '0';
        } else if (c == '1') {
            ans += '1';
        } else if (c == 'B'){
            ans = ans.substr(0, ans.size() - 1);
        }
    }
    cout << ans << endl;
}
