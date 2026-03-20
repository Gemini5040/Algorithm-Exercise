#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,m;
		cin>>n>>m;
		
		vector<int> a(m+1);
		vector<vector<int>> c(n+1,vector<int>(m+1)) , w(n+1,vector<int>(m+1));
		
		for(int i=1;i<=m;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cin>>c[i][j];
			for(int j=1;j<=m;j++) cin>>w[i][j];
		}
		
		vector<int> err(n+1);
		vector< priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > > pq(m+1);
		queue<int> q;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(c[i][j]>a[j]){
					err[i]++;
					pq[j].push({c[i][j],i});
				}
			}
			if(!err[i]) q.push(i);
		}
		
		int cnt=0;
		while(!q.empty()){
			cnt++;
			int u=q.front(); q.pop();
			for(int j=1;j<=m;j++){
				a[j]+=w[u][j];
				while(!pq[j].empty()&&a[j]>=pq[j].top().first){
					auto [c,v]=pq[j].top(); pq[j].pop();
					if(--err[v]==0) q.push(v);
				}
			}
		}
		
		if(cnt==n) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
	
	return 0;
}