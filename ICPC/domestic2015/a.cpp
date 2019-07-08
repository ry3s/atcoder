#include <iostream>
#include <vector>

using namespace std;

void solve(int m, int n_min, int n_max) {
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    int max_gap = 0;
    int ans;
    for (int i = n_min - 1; i <= n_max - 1; i++) {
        int gap = p[i] - p[i + 1];
        if (gap >= max_gap) {
            max_gap = gap;
            ans = i;
        }
    }
    cout << ans + 1<< endl;
}
int main() {
    while (true) {
        int m, n_min, n_max;
        cin >> m >> n_min >> n_max;
        if (m == 0 and n_min == 0 and n_max == 0) break;
        solve(m, n_min, n_max);
    }
}
