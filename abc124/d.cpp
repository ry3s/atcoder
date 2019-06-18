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
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    vector<LL> nums;
    if (str[0] == '0') nums.push_back(0);
    for (LL i = 0; i < (LL)str.size();) {
        LL j = i;
        while (j < (int)str.size() and str[j] == str[i]) {
            j++;
        }
        nums.push_back(j - i);
        i = j;
    }
    if (str.back() == '0') {
        nums.push_back(0);
    }

    vector<LL> sums((int)nums.size() + 1, 0);
    rep(i, nums.size()) {
        sums[i + 1] = sums[i] + nums[i];
    }

    LL res = 0;
    for (int left = 0; left < (int)sums.size(); left += 2) {
        int right = left + k * 2 + 1;

        if (right >= (int)sums.size()) {
            right = (int)sums.size() - 1;
        }
        res = max(res, sums[right] - sums[left]);
    }
    cout << res << endl;
    return 0;
}
