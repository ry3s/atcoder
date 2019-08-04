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

LL fact(LL x) {
    LL ret = 1;
    if (x <= 0) {
        return 1;
    }
    loop(i, 1, x + 1) {
        ret *= i;
    }
    return ret;
}
int main() {
    int n;
    string s;
    cin >> s;
    n = stoi(s);

    reverse(s.begin(), s.end());

    LL ans = 0;
    for (int i = s.length(); i >= 1; i--) {
        if (i % 2 == 1) {
            if (i == s.length()) {
                int digit = s[i - 1] - '0';
                if (i == 1) {
                    ans += digit;
                    continue;
                }
                int x =  (n % (int)pow(10, i - 1));
                int y = (digit - 1) * pow(10, i - 1);
                ans += x + 1 + y;
            } else {
                if (i == 1) {
                    ans += 9;
                    continue;
                }
                ans += 9 * pow(10, i - 1);
            }
        } else {
            continue;
        }
    }
    cout << ans << endl;
    return 0;
}
