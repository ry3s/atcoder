#include <iostream>

using namespace std;
typedef long long ll;

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    ll n,m;
    cin>>n>>m;
    ll c[n][n];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i==j){
                c[i][j]=0;
            }
            else c[i][j]=1e9;
        }
    }
    for(ll i=0;i<m;i++){
        ll l,r,d;
        cin>>l>>r>>d;
        l--,r--;
        c[l][r]=d;
        c[r][l]=d;
    }

    for(ll k=1;k<n;k++)for(ll i=1;i<n;i++)for(ll j=1;j<n;j++){
        c[i][j] = min(c[i][j],c[i][k] + c[k][j]);
    }
    ll ans=1e9;
    for(ll i=1;i<n;i++)for(ll j=i+1;j<n;j++){
        ll k=c[0][i]+c[i][j]+c[j][0];
        if(k>1e9) continue;
        ans=min(ans,k);
    }
    if(ans<1e9){
        cout<<ans<<endl;
    }
    else cout<<-1<<endl;


}
