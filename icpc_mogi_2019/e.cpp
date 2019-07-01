#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
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
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

struct Test {
    vector<int> a;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Test> v(n);
    rep(i, n) rep(j, m){
        int x;
        cin >> x;
        v[i].a.push_back(x);
    }
    rep(i, m) {
        stable_sort(v.begin(), v.end(), [&](auto a, auto b) {
                                            return a.a[i] < b.a[i];
                                                      });
    }
    rep(i, n) {
        rep(j, m) {
            cout << v[i].a[j] << " ";
        }
        cout << endl;
    }
}
