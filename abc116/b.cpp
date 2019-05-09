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
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
LL f(LL n) {
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return 3 * n + 1;
    }
}
int main() {
    LL s;
    cin >> s;
    vector<LL> v;
    v.push_back(-1);
    for (int i = 1; ; i++) {
        if (i == 1) {
            v.push_back(s);
        } else {
            v.push_back(f(v[i-1]));
        }
        for (int j = 1; j <=i - 1; j++) {
            for (int k = j + 1; k <= i; k++) {
                if (v[j] == v[k]) {
                    cout << k << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
