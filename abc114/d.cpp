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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;

vector<pair<LL, LL>> prime_factorize(LL n) {
    vector<pair<LL, LL>> res;

    for (LL p = 2; p * p <= n; p++) {
        if (n % p != 0) continue;

        int num_p = 0;
        while (n % p == 0) {
            num_p++;
            n /= p;
        }
        res.push_back(make_pair(p, num_p));
    }
    if (n != 1) res.push_back(make_pair(n, 1));

    return res;
}

int n;
map<LL, int> exponent;

LL rec(map<LL, int>::iterator p, LL mul) {
    if (p == exponent.end()) {
        if (mul == 1) return 1;
        else return 0;
    }

    LL res = 0;
    for (int i = 0; i < p->second + 1; i++) {
        if (mul % (i + 1) != 0) continue;

        res += rec(++p, mul / (i + 1));
        p--;
    }
    return res;
}
int main() {
    cin >> n;

    for (int i = 2; i <= n; i++) {
        auto ps = prime_factorize(i);
        for (auto it : ps) {
            exponent[it.first] += it.second;
        }
    }
    cout << rec(exponent.begin(), 75) << endl;

    return 0;
}
