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

int main() {
    string s; cin >> s;

    int index = 0;
    while (index + 1 < s.size()){
        if (s[index] == s[index + 1]) {
            cout << index + 1 << " " << index + 2 << endl;
            return 0;
        }
        index++;
    }

    index = 0;
    while (index + 2 < s.size()) {
        if (s[index] == s[index + 2]) {
            cout << index + 1 << " " << index + 3 << endl;
            return 0;
        }
        index++;
    }

    cout << "-1 -1" << endl;

}
