#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define EMPTY 0
#define WHITE 1
#define BLACK 2

using namespace std;

int rev_col(int c) {
    if (c == WHITE)
        return BLACK;
    return WHITE;
}
int n, m;
bool edge[1000000];
int color[1000];
bool solve(int cur_color, int i) {
    color[i] = cur_color;
    REP(j,n) {
        if (edge[i*1000+j] == false)
            continue;
        if (color[j] == EMPTY) {
            if (!solve(rev_col(cur_color), j)) {
                return false;
            }
        } else if (color[j] != rev_col(cur_color))
            return false;
    }
    return true;
}
int main() {
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        fill(edge, edge+1000000, false);
        REP(i, m) {
            int u, v;
            cin >> u >> v;
            edge[(u-1)*1000+v-1] = true;
            edge[(v-1)*1000+u-1] = true;
        }
        // i=0 kara miteiku
        fill(color, color+1000, EMPTY);
        if (!solve(WHITE, 0)) {
            cout << 0 << endl;
        } else {
            int count = 0;
            REP(i, n)
                if (color[i] == WHITE)
                    ++count;
            if (count % 2 == 0 && (n-count) % 2 == 0 && count != n-count) {
                cout << 2 << endl;
                cout << min(count / 2, (n - count) / 2) << endl;
                cout << max(count / 2, (n - count) / 2) << endl;
            } else if (count % 2 == 0) {
                cout << 1 << endl;
                cout << count / 2 << endl;
            } else if ((n - count) % 2 == 0) {
                cout << 1 << endl;
                cout << (n - count) / 2 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
