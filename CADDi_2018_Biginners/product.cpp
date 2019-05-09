#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long long n, a;
  vector<long long> v;
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);

  }
  vector<long long>::iterator it = v.begin();
  vector<long long>::iterator it_end = v.end();

  while (it != it_end) {
    if (*it % 2 != 0) {
      cout << "first" << endl;
      return 0;
    }
    it++;
  }

  cout << "second" << endl;

  return 0;
}

    
  
