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
int compare(string a, string b) {
    if (a.size() < b.size()) {
        return -1;
    } else if (a.size() > b.size()) {
        return 1;
    } else {
        rep(i, a.size()) {
            if (a[i] < b[i]) {
                return -1;
            } else if (a[i] > b[i]) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    string a, b; cin >> a >> b;
    int res = compare(a, b);
    if (res == 0) {
        cout << "EQUAL" << endl;
    } else if (res == -1) {
        cout << "LESS" << endl;
    } else {
        cout << "GREATER" << endl;
    }

}
