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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
using ULL = unsigned long long;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    int cnt = 0;
    for (int i = min(a, b); i >= 1; i--) {
        if ((a % i == 0) and (b % i == 0)) {
            cnt++;

            if (cnt == k) {
                cout << i << endl;
                return 0;
            }
        }
    }
}
