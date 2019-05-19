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
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    if (str[k-1] == 'A') str[k-1] = 'a';
    if (str[k-1] == 'B') str[k-1] = 'b';
    if (str[k-1] == 'C') str[k-1] = 'c';
    cout << str << endl;
    return 0;
}
