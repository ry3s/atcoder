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

int count_digit(long long n)
{
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> table(9, vector<int>(9, 0));

    for (int i = 1; i <= n; i++) {
        if (i % 10 == 0) continue;
        if (i <= 9) {
            table[i - 1][i - 1] = 1;
            continue;
        }
        int count = count_digit(i);
        int most = i / (int)pow(10, count - 1);
        int least = i % 10;
        table[most - 1][least - 1]++;
    }

    long long ans = 0;
    // rep(i, 9) {
    //     rep(j, 9) {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    rep(i, 9) {
        for (int j = i; j < 9; j++) {
            if (i == j) {
                if (table[i][j] == 1) ans += 1;
                else ans += table[i][j] * table[i][j];
            } else {
                ans += table[i][j] * table[j][i] * 2;
            }
        }
        cout << endl;
    }
    cout << ans << endl;
}
