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

LL rec(int level, LL x) {
    if (level == 0) return 1;

    LL len = (1LL << (level + 1)) - 3;
    LL num_p = (1LL << level) - 1;

    if (x == 1) return 0;
    else if (x <= len + 1) return rec(level - 1, x - 1);
    else if (x == len + 2) return num_p + 1;
    else if (x <= (len + 1) * 2) return num_p + 1 + rec(level - 1, x - len - 2);
    else return num_p * 2 + 1;
}
int main() {
    int n; LL x;
    cin >> n >> x;
    cout << rec(n, x) << endl;
    return 0;
}
