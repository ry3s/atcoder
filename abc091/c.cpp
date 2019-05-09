#include <cstdio>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <bitset>
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define mod 1000000007
using namespace std;
typedef long long int LL;

bool comp_x_greater(pair<int, int> &a, pair<int, int> &b) {
    return a.first  < b.first;
}
bool comp_y_lower(pair<int, int> &a, pair<int, int> &b) {
    return a.second  > b.second;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int> > red;
    vector<pair<int, int> > blue;

    rep(i, N) {
        int a, b;
        cin >> a >> b;
        red.push_back(make_pair(a, b));
    }
    rep(i, N) {
        int c, d;
        cin >> c >> d;
        blue.push_back(make_pair(c, d));
    }
    sort(red.begin(), red.end(), comp_y_lower);
    sort(blue.begin(), blue.end(), comp_x_greater);

    int cnt = 0;
    bool is_used[N];
    rep(i, N)  {
        is_used[i] = false;
    }
    rep(b, N) {
        rep(a, N) {
            if (red[a].first < blue[b].first
                and red[a].second < blue[b].second
                and is_used[a] == false) {
                cnt++;
                is_used[a] = true;
                break;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
