#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;
bool is_prime(const unsigned n){
    switch(n){
        case 0: // fall-through
        case 1: return false;
        case 2: // fall-through
        case 3: return true;
    } // n > 3 が保証された

    if(n%2 == 0) return false;
    if(n%3 == 0) return false;
    // 2と3の倍数でないので6の倍数ではないことが保証された

    if(n%6 != 1 && n%6 != 5) return false;
    // 6の倍数前後の数(素数かもしれない数)であることが保証された

    // 6の倍数前後の数を使って試し割りをする
    for(unsigned i=5;i*i<=n;i+=6){
        if(n%i     == 0) return false; // 6n-1
        if(n%(i+2) == 0) return false; // 6n+1
    }

    return true;
}

int main() {
    int x; cin >> x;

    for (long long i = x; ; i++) {
        if (is_prime(i)) {
            cout << i << endl;
            return 0;
        }
    }
}
