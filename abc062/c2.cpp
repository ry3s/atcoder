#include <iostream>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	ll H,W;
	cin >> H >> W;

	ll ans = INF*INF;
	ll a=0,b=0,c=0;

	for(int h = 0; h <= H; h++){
		if(W%2==0) a = h*W/2,b = h*W/2;
		else a = h*(W-1)/2,b = h*(W+1)/2;
		c = W*(H-h);

		ll s_max = max(max(a,b),c);
		ll s_min = min(min(a,b),c);
		if(s_max - s_min < ans) ans = s_max - s_min;

		a = h*W;
		if((H-h)%2==0) b = (H-h)/2 * W,c = b;
		else b = (H-h-1)/2 * W,c = (H-h+1)/2 * W;

		s_max = max(max(a,b),c);
		s_min = min(min(a,b),c);
		if(s_max - s_min < ans) ans = s_max - s_min;
	}

	for(int w = 0; w <= W; w++){
		if(H%2==0) a = H/2*w, b = a;
		else a = (H-1)/2*w, b = (H+1)/2*w;
		c = H*(W-w);

		ll s_max = max(max(a,b),c);
		ll s_min = min(min(a,b),c);
		if(s_max - s_min < ans) ans = s_max - s_min;

		a = w*H;
		if((W-w)%2==0) b = H*(W-w)/2 , c = b;
		else b = H*(W-w-1)/2, c = H*(W-w+1)/2;
		s_max = max(max(a,b),c);
		s_min = min(min(a,b),c);
		if(s_max - s_min < ans) ans = s_max - s_min;
	}

	cout << ans << endl;

	return 0;
}
