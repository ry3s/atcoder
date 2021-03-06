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

LL oddsolve(LL a) {
    return (a + 1) / 2 % 2;
}

LL solve(LL a) {
    if (a % 2 == 1) {
        return oddsolve(a);
    } else {
        return oddsolve(a + 1) ^ (a + 1);
    }
}
int main() {
    LL a, b;
    cin >> a >> b;
    cout << (solve(b) ^ solve(a - 1)) << endl;

    return 0;
}
