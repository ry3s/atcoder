#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

typedef struct {
  int city;
  int year;
  int prefecture;
  int id;
} City;
int main() {
  int n, m;
  int p, y;
  City tmpc;
  vector<City> v;
  cin >> n >> m;
  rep(i, m) {
    cin >> p >> y;
    tmpc.city = i;
    tmpc.year = y;
    tmpc.prefecture = p;
    tmpc.id = -1;
    v.push_back(tmpc);
  }
  sort(v.begin(), v.end(), [](const City &a, const City &b) {
                             return a.prefecture == b.prefecture
                               ? a.year < b.year : a.prefecture < b.prefecture ;
                           });
  // sort(v.begin(), v.end(), [](const City &a, const City &b) {
  //                            return a.year < b.year;
  //                          });
  // rep(i, m) {
  //   cout << v[i].prefecture << " " <<  v[i].year << endl;
  // }
  int nowp = v[0].prefecture;
  int cnt = 0;
  rep(i, m) {
    if (v[i].prefecture == nowp) {
      cnt++;
      v[i].id = cnt;
    } else {
      cnt = 1;
      nowp = v[i].prefecture;
      v[i].id = 1;
    }
  }
  sort(v.begin(), v.end(), [](const City &a, const City &b) {
                             return a.city < b.city;
                           });
  rep(i, m) {
    printf("%06d%06d\n", v[i].prefecture, v[i].id);
  }
  return 0;
}
