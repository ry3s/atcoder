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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;

int main() {
    string a, b, c; cin >> a >> b >> c;
    string x = a + b + c + "+";

    sort(x.begin(), x.end());

    int maxi = 0;

    do {
        if (x[0] == '+' or x[3] == '+') continue;

        if (x[1] == '+') {
            int tmp = (x[0] - '0') + (x[2] - '0') * 10 + (x[3] - '0');
            maxi = max(maxi, tmp);
        } else {
            int tmp = (x[0] - '0') * 10 + (x[1] - '0') + (x[3] - '0');
            maxi = max(maxi, tmp);
        }

    } while (next_permutation(x.begin(), x.end()));
    cout << maxi << endl;
}
