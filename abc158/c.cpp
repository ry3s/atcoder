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
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;

int main() {
    int a, b; cin >> a >> b;

    for (int x = 1; x <= 1000; x++) {
        if ((int)floor(x * 0.08) == a
            &&(int)floor(x * 0.1) == b) {
            cout << x << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}
