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
    string s; cin >> s;

    int ans = 0;
    if (s == "SUN") {
        ans = 7;
    } else if (s == "MON") {
        ans = 6;
    } else if (s == "TUE") {
        ans = 5;
    } else if (s == "WED") {
        ans = 4;
    } else if (s == "THU") {
        ans = 3;
    } else if (s == "FRI") {
        ans = 2;
    } else if (s == "SAT") {
        ans = 1;
    }
    cout << ans << endl;
}
