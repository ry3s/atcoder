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
    const string str[17] =
        {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S",
         "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};

    float dis_table[14] =
        {0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8,
         17.1, 20.7, 24.4, 28.4, 32.6, 200.0};

    float deg, dis; cin >> deg >> dis;

    deg /= 10;
    dis /= 60;
    dis = round(dis * 10) / 10;

    int dis_ans = 0;;
    rep(i, 13) {
        if (dis <= dis_table[i]) {
            dis_ans = i;
            break;
        }
    }

    double current = 11.25;
    int index = 0;

    if (dis_ans == 0) {
        cout << "C" << " " << 0 << endl;
        return 0;
    } else {
        rep(i, 17) {
            if (deg < current) {
                index = i;
                break;
            }
            current += 22.5;
        }
    }
    cout << str[index] << ' ' << dis_ans << endl;

}
