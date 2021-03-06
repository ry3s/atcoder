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

    int n = str.size();
    int first = 0, last = 0;
    rep(i, n) {
        if (str[i] == 'A') {
            first = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == 'Z') {
            last = i;
            break;
        }
    }
    int len = last - first + 1;

    cout << len << endl;
}
