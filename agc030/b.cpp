#include <iostream>
#include <list>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

LL solve(LL l, list<LL> li, LL road, LL now) {
  LL ft, bk;
  if (li.empty()) {
    //cout << road << endl;
    return road; 
  } else if (li.size() == 1) {
    ft = li.front(); li.pop_front();
    if (ft < now) {
      //cout << max( now - ft + road,  l - now + ft + road) << endl;
      // cout << now - ft + road << endl;
      // cout << l - now + ft + road << endl;
      return max( now - ft + road,  l - now + ft + road);
    } else {
      //cout << max(ft - now + road, now + l - ft + road) << endl;
      // cout << ft - now + road << endl;
      // cout << now + l - ft + road << endl;
      return  max(ft - now + road, now + l - ft + road);
    }
  } else {
    ft = li.front();
    bk = li.back();
    if (ft > now and bk > now) {
      list<LL> tmp = li;
      tmp.pop_front();
      LL x = solve(l, tmp, ft - now + road, ft);
      list<LL> tmp2 = li;
      
      tmp2.pop_back();
      LL y = solve(l, tmp2, l - bk + now + road, bk);
      return max(x, y);
    } else if (ft < now and bk > now) {
      list<LL> tmp = li;
      tmp.pop_front();
      LL x = solve(l, tmp, now - ft + road, ft);

      list<LL> tmp2 = li;
      tmp2.pop_back();
      LL y = solve(l, tmp2, bk - now + road, bk);
      return max(x, y);
    } else {
      list<LL> tmp = li;
      tmp.pop_front();
      LL x = solve(l, tmp, l - now + ft + road, ft);

      list<LL> tmp2 = li;
      tmp2.pop_back();
      LL y = solve(l, tmp2, now - bk + road, bk);
      return max(x, y);
    }
    // if (ft > now and bk > now) {
    //   list<LL> tmp2 = li;
    //   tmp2.pop_back();
    //   solve(l, tmp2, l - bk + now + road, bk);
    // } else if (ft < now and bk > now) {
    //   list<LL> tmp2 = li;
    //   tmp2.pop_back();
    //   solve(l, tmp2, bk - now + road, bk);
    // } else {
    //   list<LL> tmp2 = li;
    //   tmp2.pop_back();
    //   solve(l, tmp2, now - bk + road, bk);
    // }


  }
  
}
int main() {
  LL l, n, x;
  cin >> l >> n;
  list<LL> li;
  rep(i, n) {
    cin >> x;
    li.push_back(x);
  }
  cout << solve(l, li, 0, 0)  <<endl;
}
