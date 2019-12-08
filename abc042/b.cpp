#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, l; cin >> n >> l;

    vector<string> ss(n);
    for (int i = 0; i < n; i++) {
        cin >>  ss[i];
    }

    sort(ss.begin(), ss.end());

    string ans = "";
    for (auto s: ss) {
        ans += s;
    }

    cout << ans << endl;
}
