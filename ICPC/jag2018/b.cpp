#include <iostream>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define PB push_back

int main() {
    while (true) {
        int n, l, r;
        cin >> n >> l >> r;
        if (n == 0 && l == 0 && r == 0)
            break;
        vector<int> v[2];
        FOR(i,l,r+1)
            v[0].PB(i);

        int res = 0;
        REP(i, n) {
            int a;
            cin >> a;
            v[1-i%2].erase(v[1-i%2].begin(), v[1-i%2].end());
            int count = 0;
            for (const auto & e : v[i%2]) {
                if (e % a == 0)  {
                    ++count;
                }
                else
                    v[1-i%2].PB(e);
            }
            if (i % 2 == 0)
                res += count;
        }
        if (n % 2 == 0)
            res += v[0].size();
        cout << res << endl;
    }
}
