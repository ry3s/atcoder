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
    int N;
    cin >> N;

    int m = 0, a = 0, r = 0, c = 0, h = 0;
    rep(i, N) {
        string str;
        cin >> str;

        if (str[0] == 'M') {
            m++;
        } else if (str[0] == 'A') {
            a++;
        } else if (str[0] == 'R') {
            r++;
        } else if (str[0] == 'C') {
            c++;
        } else if (str[0] == 'H') {
            h++;
        }
    }

    if (m + a + r + c + h < 3) {
        cout << 0 << endl;
        return 0;
    }
    LL ret = 0;
    LL arr[5] = { m, a, r, c, h };
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                ret += arr[i] * arr[j] * arr[k];
            }
        }
    }
    cout << ret << endl;
}
