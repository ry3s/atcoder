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
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };

    int n; cin >> n;
    for (int i = 0; i < n % 30; i++) {
        swap(arr[i % 5], arr[i % 5 + 1]);
    }

    for (auto x: arr) {
        cout << x;
    }
    cout << endl;
}
