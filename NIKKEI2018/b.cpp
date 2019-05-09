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
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;

    int cnt = 0;
    rep(i, n) {
        if (a[i] == b[i] and b[i] == c[i]) {

        } else if (a[i] != b[i]  and b[i] != c[i] and c[i] != a[i]) {
            cnt += 2;
        } else {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
