#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;

template<typename T>
struct BellmanFord{
	struct Edge{
		int  from,to; ll cost;
		Edge(){}
		Edge(int from,int to,ll cost):from(from),to(to),cost(cost){}
	};

	int n;
	vector<vector<int> >G;
	vector<int> used,reach;
	BellmanFord(int n):n(n),G(n),used(n,0),reach(n,0){}

	vector<Edge> es;
	void add_edge(int from,int to,ll cost){
		es.push_back(Edge(from,to,cost));
		G[from].push_back(to);
	}

	void dfs(int v){
		if(used[v])return ;
		used[v]=1;
		for(int u:G[v]){
			dfs(u);
		}
	}
	ll build(int from,int to,int &neg_loop){
		for(int i=0;i<n;i++){
			fill(used.begin(),used.end(),0);
			dfs(i);
			reach[i]=used[to];
		}
		vector<ll> ds(n,1e18);
		ds[from]=0;
		for(int i=0;i<n;i++){
			bool update=0;
			for(auto e:es){
				if(!reach[e.from]||!reach[e.to]||ds[e.from]==1e18) continue;
				if(ds[e.to]>ds[e.from]+e.cost){
					ds[e.to]=ds[e.from]+e.cost;
					update=1;
				}
			}
			if(!update)break;
			if(i==n-1){
				neg_loop=1;
				return 1e18;
			}
		}
		neg_loop=0;
		return ds[to];
	}
};

int main(){
	int n,m,p; cin >> n >> m >> p;
	BellmanFord<int> G(n);
	for(int i=0;i<m;i++){
		int a,b,c; cin >> a >> b >> c;
		a--; b--;
		G.add_edge(a,b,p-c);
	}
	int neg_loop;
	int res=G.build(0,n-1,neg_loop);
	if(neg_loop){
		cout << -1 << endl;
		return 0;
	}
	else{
		cout << max((ll)0,(ll)-res) << endl;
		return 0;
	}
}
