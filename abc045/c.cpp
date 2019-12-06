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
    string str; cin >> str;
    int n = str.length();

    long long ans = 0;
    for (int bit = 0; bit < (1 << (n - 1)); bit++) {
        string exp = {str[0]};
        long long sum = 0;
        rep(i, n - 1) {
            if (bit & (1 << i)) {
                exp += str[i + 1];
            } else {
                sum += stoi(exp);
                exp = str[i + 1];
            }
        }
        if (exp != "") {
            sum += stoll(exp);
        }
        ans += sum;
    }
    cout << ans << endl;
}
