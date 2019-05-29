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
LL euclidean_gcd(LL a, LL b) {
  if(a < b) return euclidean_gcd(b, a);
  LL r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main() {
    int n;
    cin >> n;
    rep(i, n) {
        LL a, b;
        cin >> a >> b;
        cout << euclidean_gcd(a, b) << endl;
    }
}
