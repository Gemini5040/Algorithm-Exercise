#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=100010;
vector<tuple<ll,ll,ll>> g[N];
ll dp[N];
ll s,t;

void dfs(int father,int u){
	for(auto [v,p,q]:g[u]){
		if(v==father) continue;
		dfs(u,v);
		dp[u]+=max(0LL,dp[v]+p+q);
	}
}

pair<bool,ll> solve(int father,int u){
	if(u==t) return make_pair(true,dp[t]);
	bool flag=false;
	ll res=0;
	for(auto [v,p,q]:g[u]){
		if(v==father) continue;
		auto [ff,val]=solve(u,v);
		if(ff){
			flag=true;
			res+=val+p;
		}else{
			res+=max(0LL,dp[v]+p+q);
		}
	}
	
	return make_pair(flag,res);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		fill(dp,dp+N,0);
		
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			ll u,v,p,q;
			cin>>u>>v>>p>>q;
			g[u].emplace_back(v,p,q);
			g[v].emplace_back(u,q,p);
		}
		cin>>s>>t;
		
		dfs(0,s);
		auto [flag,ans]=solve(0,s);
		cout<<ans<<"\n";
	}
	
	return 0;
}
