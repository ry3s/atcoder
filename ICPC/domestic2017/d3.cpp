#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <cstring>
using namespace std;
using vi = vector<int>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

short dp[2][1 << 20];

template<int SZ> int solve(int n, int m){
	if(SZ / 2 >= m) return solve<SZ / 2>(n, m); //bitsetのサイズを小さくしても大丈夫なら小さくする。（ただの高速化）

	int ans = 0;
	vector<bitset<SZ>> b(n);

	rep(i, n){
		string s; cin >> s;
		rep(j, m) if(s[j] == '1') b[i][j] = 1;
	}
	rep(mask, 1 << n){
		int k = __builtin_popcount(mask);
		if(ans >= k) continue;

		bitset<SZ> sum;
		rep(i, n) if(mask & 1 << i) sum ^= b[i];
		if(sum.none()) ans = max(ans, k);
	}
	return ans;
};
int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	int n, m;
	while(cin >> n >> m, n){
		if(m > 20){
			cout << solve<512>(n, m) << endl;
		}
		else{
			memset(dp, -1, sizeof(dp));
			vi b(n);
			rep(i, n){
				string s; cin >> s;
				rep(j, m) if(s[j] == '1') b[i] |= 1 << j;
			}

			dp[0][0] = 0;
			int cur = 0, next = 1;
			rep(i, n){
				memcpy(dp[next], dp[cur], sizeof(dp[cur]));
				rep(j, 1 << m) if(dp[cur][j] >= 0){
					dp[next][j ^ b[i]] = max(dp[next][j ^ b[i]], (short)(dp[cur][j] + 1));
					//dp[next][j] = max(dp[next][j], dp[cur][j]);
				}
				swap(cur, next);
			}
			cout << dp[cur][0] << endl;
		}
	}
	return 0;
}
