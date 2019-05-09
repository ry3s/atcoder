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
    LL n;
    cin >> n;
    string str = "";

    while (n != 0) {
        LL r = n % 2;
        if (r < 0) r += 2;

        n = (n - r) / (-2);

        str += (char)('0' + r);
    }

    reverse(str.begin(), str.end());

    if (str == "") str = "0";

    cout << str << endl;
    return 0;
}
