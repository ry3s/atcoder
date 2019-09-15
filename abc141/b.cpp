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
    string s; cin >> s;

    int n = s.size();
    rep(i, n) {
        if (i % 2 == 0) {
            if (s[i] == 'R' or s[i] == 'U' or s[i] == 'D') {

            } else {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (s[i] == 'L' or s[i] == 'U' or s[i] == 'D') {

            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
