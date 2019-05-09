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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    string str;
    cin >> str;
    vector<int> v;
    for (char x : str) {
        v.push_back(atoi(&x));
    }

    for (int bit = 0; bit < (1 << 3); bit++) {
        string res;
        res = to_string(v[0]);
        int ans = v[0];
        rep(i, 3) {
            if (bit & (1 << i)) {
                res += "+";
                ans += v[i + 1];
            } else {
                res += "-";
                ans -= v[i + 1];
            }
            res += to_string(v[i + 1]);
        }
        if (ans == 7) {
            cout << res <<  "=7" << endl;
            return 0;
        }

    }
    return 0;
}
