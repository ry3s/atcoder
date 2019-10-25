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
    int n, m; cin >> n >> m;
    vector<pair<int64_t, int64_t>> students(n);
    vector<pair<int64_t, int64_t>> check_points(m);
    rep(i, n) {
        int64_t a, b; cin >> a >> b;
        students[i] = {a, b};
    }
    rep(i, m) {
        int64_t c, d; cin >> c >> d;
        check_points[i] = {c, d};
    }

    for (const auto &student: students) {
        int64_t mini = 1LL << 60;
        int ans = 0;
        rep(i, m) {
            auto point = check_points[i];
            auto dist = abs(student.first - point.first)
                + abs(student.second - point.second);
            if (dist < mini) {
                mini = dist;
                ans = i + 1;
            }
        }
        cout << ans << endl;
    }
}
