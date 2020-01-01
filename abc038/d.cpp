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
    int n; cin >> n;
    vector<pair<int, int>> boxes(n);
    rep(i, n) {
        int h, w; cin >> w >> h;
        boxes[i] = { w, h };
    }

    stable_sort(boxes.begin(), boxes.end(), [](auto a, auto b) {
                                                return a.first < b.first;
                                            });
    stable_sort(boxes.begin(), boxes.end(), [](auto a, auto b) {
                                                return a.second < b.second;
                                            });

    pair<int, int> prev = { 0, 0 };
    int ans = 0;
    for (const auto& box: boxes) {
        if (box.first > prev.first && box.second > prev.second) {
            ans++;
            prev = box;
        }
    }
    cout << ans << endl;
}
