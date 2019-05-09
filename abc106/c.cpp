#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <bitset>
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(val) cout << "!!!" << #val << ": " << val << endl
#define mod 1000000007
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    string str;
    LL k;
    cin >> str >> k;

    rep(i, min((long long)str.length(), k)) {
        if (str[i] != '1') {
            cout << str[i] << endl;
            return 0;
        }
    }
    cout << '1' << endl;
    return 0;
}
