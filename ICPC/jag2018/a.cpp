#include <cstdio>
#include <climits>
#include <cassert>
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


void solve(string g, int y, int m, int d) {
    if (y > 31) {
        cout << "?" << " "<< y - 30 << " " << m << " " << d << endl;
    } else if (y == 31 and m >= 5){
        cout << "?" << " "<< 1 << " " << m << " " << d << endl;
    } else {
        cout << g << " "<< y << " " << m << " " << d << endl;
    }
}
int main() {
    while (true) {
        string g;
        int y, m, d;
        cin >> g;
        if (g == "#") break;
        cin >> y >> m >> d;
        solve(g, y, m, d);
    }
}
