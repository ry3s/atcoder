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
    string a, b; cin >> a >> b;
    int x = stoi(a) == 1 ? 14 : stoi(a);
    int y = stoi(b) == 1 ? 14 : stoi(b);

    if (x == y) {
        cout << "Draw" << endl;
    } else if (x < y) {
        cout << "Bob" << endl;
    } else  {
        cout << "Alice" << endl;
    }
}
