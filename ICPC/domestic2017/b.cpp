#include <cstdio>
#include <climits>
#include <cassert>
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

int main() {
    while (true) {
        string s1, s2;
        vector<string> sv1, sv2;
        string tmp ="";
        LL cnt = 0;

        cin >> s1;
        if (s1 == ".") break;
        cin >> s2;

        if (s1 == s2) {
            cout << "IDENTICAL" << endl;
        } else {
            rep(i, s1.size() + 1)  {
                if (s1[i] != '"' and i != s1.size()) {
                    tmp += s1[i];
                } else {
                    sv1.push_back(tmp);
                    tmp = "";
                }
            }
            rep(i, s2.size() + 1) {
                if (s2[i] != '"' and i != s2.size()) {
                    tmp += s2[i];
                } else {
                    sv2.push_back(tmp);
                    tmp = "";
                }
            }
            if (sv1.size() !=sv2.size()) {
                cnt += 2;
            } else {
                rep(i, sv1.size()) {
                    if (sv1[i] != sv2[i] and i % 2 == 1) {
                        cnt++;
                    } else if (sv1[i] != sv2[i]){
                        cnt += 2;
                        break;
                    }
                }
            }
            cout << ((cnt == 1) ? "CLOSE" : "DIFFERENT") << endl;
        }
    }
    return 0;
}
