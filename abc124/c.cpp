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
    string s;
    cin >> s;

    LL ans = 0;
    LL n = s.length();

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            ans++;
            if (s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
    }

    cout << ans << endl;
    return 0;
}
