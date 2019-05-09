#include <cstdio>
#include <climits>
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
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    string str;
    cin >> str;
    int n = str.length();
    LL res = 0;
    for (unsigned bit = 0; bit < (1 << (n - 1)); bit++) {
        int left = 0;
        for (int i = 0; i < n - 1; i++) {
            if (bit & (1 << i)) {
                res += stoll(str.substr(left, i + 1 - left));
                left = i + 1;
                // cout << res << endl
                    ;
            }
        }
        if (left < n) {
            res += stoll(str.substr(left, n - left + 1));
            // cout << res << endl;
        }
    }

    cout << res << endl;
    return 0;
}
