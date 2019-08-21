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
    string str;
    cin >> str;
    string pre = "", cur = "";

    pre = str[0];
    LL cnt = 1;
    for (int i = 1; i < (int)str.size(); i++) {
        cur += str[i];

        if (pre != cur) {
            pre = cur;
            cur = "";
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
