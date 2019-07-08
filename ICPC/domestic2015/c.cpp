#include <iostream>
#include <vector>
#include <string>

#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;

int idx = 0;
int solve(vector<string>& v, int indent) {
    char c = v[idx].back();
    if (c == '+') {
        int res = 0;
        ++idx;
        while (idx < v.size() && indent + 1 == v[idx].size() - 1)
            res += solve(v, indent+1);
        return res;
    } else if (c == '*') {
        int res = 1;
        ++idx;
        while (idx < v.size() && indent + 1 == v[idx].size() - 1)
            res *= solve(v, indent+1);
        return res;
    } else {
        return v[idx++].back() - '0';
    }
}
int main() {
    while (true) {
        idx = 0;
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<string> v;
        REP(i,n) {
            string s;
            cin >> s;
            v.push_back(s);
        }
        cout << solve(v, 0) << endl;
    }
}
