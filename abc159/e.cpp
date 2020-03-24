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
int count_bits(int bits) {
    int num = 0;
    while (bits != 0) {
        num++;
        bits &= bits - 1;
    }
    return num;
}
int main() {
    int h, w, k; cin >> h >> w >> k;
    vector<string> arr(h);
    rep(i, h) cin >> arr[i];


    int ans = h * w + 1;
    for (int mask = 0; mask < (1 << (h - 1)); mask++) {
        vector<pair<int, int>> kugiri;
        {
            int y = 1;
            int prev = 0;
            rep(i, h - 1) {
                if ((mask >> i) & 1) {
                    kugiri.push_back({y, prev});
                    prev = y;
                }
                y++;
            }
            kugiri.push_back({y, prev});

        }

        int left = 0;
        int right = 1;
        int cnt = (int)kugiri.size() - 1;
        while (right < w + 1) {
            bool all_ok = true;

            for (auto p: kugiri) {
                int n_white = 0;
                for (int y = p.second; y < p.first; y++) {
                    for (int x = left; x < right; x++) {
                        if (arr[y][x] == '1') n_white++;
                    }
                }
                if (n_white > k) all_ok = false;
            }

            if (all_ok) {
                right++;
            } else if (right == w || right == 1) {
                goto label;
            } else if (left == right - 1){
                goto label;
            } else {
                cnt++;
                left = right - 1;
            }

        }
        ans = min(ans, cnt);
    label:;
    }
    cout << ans << endl;
}
