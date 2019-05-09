#include <cstdio>
#include <climits>
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
#define mod 1000000007
using namespace std;
typedef long long int LL;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    if (a + b <= n) {
        cout << min(a, b) << " " << 0 << endl;
    } else {
        cout << min(a, b) << " " << (a + b) - n<< endl;
    }
    return 0;
}
