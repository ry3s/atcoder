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
    string s; cin >> s;

    int ans = 0;
    for (int left = 0; left < n - 1; left++) {
        int right = left + 1;
        while (right < n) {
            int length = 0;
            while (left + length < right
                   and right + length < n
                   and s[left + length] == s[right + length]) {
                length++;
            }
            ans = max(ans, length);
            while (right < n) {
                right++;
                if (s[left] == s[right]) break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
