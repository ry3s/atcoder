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
    vector<int> v(5);
    rep(i, 5) {
        cin >> v[i];
    }
    int k;
    cin >> k;
    rep(i, 4) {
        loop(j, 1, 5) {
            if (abs(v[i] - v[j]) > k){
                cout << ":("  << endl;
                return 0;
            }
        }
    }
    cout << "Yay!" << endl;
    return 0;
}
