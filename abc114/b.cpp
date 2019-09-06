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

int str2int(string s) {
    return (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0');
}
int main() {
    string s;
    cin >> s;

    int n = s.size();
    int ans = 1e9;
    rep(i, n - 2) {
        string x = s.substr(i, i + 3);
        int c = str2int(x);
        ans = min(ans, abs(753 - c));
    }
    cout << ans << endl;
    return 0;

}
