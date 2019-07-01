a#include <cstdio>
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
    char a = str[0];
    if (a == str[1]) {
        if (str[2] == str[3] and str[2] != a) {
            cout << "Yes" << endl;
            return 0;
        }
    } else if (a == str[2]) {
        if (str[1] == str[3] and str[1] != a) {
            cout << "Yes" << endl;
            return 0;
        }
    } else if (a == str[3]) {
        if (str[1] == str[2] and str[1] != a) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
