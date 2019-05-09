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
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
struct State {
    State() {
        point = 0;
        left = 0;
        right = 0;
    }
    LL point;
    int left;
    int right;
};
bool check_ans(vector<int> h){
    rep(i, h.size()) {
        if (h[i] != 0) return false;
    }
    return true;
}
bool check(vector<int> h, int left, int right){
    for (int i = left; i <= right; i++) {
        if (h[i] == 0) return false;
    }
    return true;
}

void calc_cost(vector<State> &v, vector<int> h, int n) {
    sort(v.begin(), v.end(), [] (const State &a, const State &b) {
                                 if (a.left != b.left) return a.left < b.left;
                                 else return a.right < b.right;
                             });
    rep(i, n) {
        for (int j = i; j < n; j++) {
            State tmp;
            tmp.left = i;
            tmp.right = j;
            LL point = 0;
            for (int k = i; k <= j; k++) {
                if (h[k] == 0) {
                    point = 0;
                    break;
                } else {
                    point += h[k];
                }
            }

            tmp.point = point;
            v[i + n * j] = tmp;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> h;
    LL sum = 0;
    rep(i, n) {
        int x;
        cin >> x;
        h.push_back(x);
        sum += x;
    }

    vector<State> v(n * n);
    calc_cost(v, h, n);
    sort(v.begin(), v.end(), [](const State &a, const State &b) {
                                 return a.point > b.point;
                             });
    LL cnt = 0;

    rep(gggg, n*n) {
        int i = 0;
        while (v[i].point >= sum) {
            i++;
        }
        if (v[i].point == 0) break;

        int left = v[i].left;
        int right = v[i].right;
        cout << "!" << endl;
        if (check(h, left, right)) {
            continue;
        } else {
            for (int j = left; j <= right; j++) {
                h[j]--;
                cout << h[j] << endl;
            }
            cnt++;
            if (check_ans(h)) {
                cout << cnt << endl;
                return 0;
            }
        }
        calc_cost(v, h, n);
        sort(v.begin(), v.end(), [](const State &a, const State &b) {
                                     return a.point > b.point;
                                 });


    }

    rep(i, n) {
        rep(j, n) {
            cout << v[i + n * j].point << " ";
        }
        cout << endl;
    }
    return 0;
}
