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
    LL N, M;
    cin >> N >> M;

    if (N == 1 and M == 1) {
        cout << 1 << endl;
    } else if (N == 1) {
        cout << (M - 2) << endl;
    } else if (M == 1) {
        cout << (N - 2) << endl;
    }  else {
        cout << (N - 2) * (M - 2) << endl;
    }

    return 0;
}
