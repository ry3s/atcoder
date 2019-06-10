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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    string str;
    cin >> str;
    ULL x = 0;
    int base = 1;
    for (int i = str.size() - 1; i >= 0; i--) {
        int n = 0;
        if (str[i] == '0') {
            n = 0;
        } else {
            n = 1;
        }

        x += n * base;
        base = base * 2;
    }
    cout  << x  << endl;
}
