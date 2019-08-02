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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vector<int> put;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            put.push_back(i + 1);

            int tmp = 1;
            int x = i + 1;
            while (tmp * tmp <= x) {
                if (x % tmp == 0) {
                    a[tmp - 1] ^= 1;
                    if (tmp != x / tmp) {
                        a[n / tmp - 1] ^= 1;
                    }
                }
                tmp +=1;
            }
        }
    }

    if (put.size() > 0) {
        cout << put.size() << endl;
        rep(i, put.size()) {
            if (i == (int)put.size() - 1) cout << put[i] << endl;
            else cout << put[i] << " ";
        }
    } else {
        cout << 0 << endl;
    }
}
