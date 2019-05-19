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

// tree DFS

using Graph = vector<vector<int> >;
Graph graph;

void dfs(int v, int parent) {
    for (auto nv : graph[v]) {
        if (nv == parent) continue; // 逆流防止
        dfs(nv, v);
    }
}
// int main() {
//     int root = 0;
//     dfs(root, -1); // root の parent は -1
// }
