#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		
		vector<vector<int>> g(n+1,vector<int>(m+1));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>g[i][j];
			}
		}
		
		vector<int> all(k+1,m+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			vector<int> row(k+1,m+1);
			for(int j=1;j<=m;j++){
				int t=g[i][j];
				row[t]=min(row[t],j);
			}
			
			for(int j=1;j<=k;j++){
				all[j]=min(all[j],row[j]);
			}
			
			int flag=1;
			int st=0;
			for(int j=1;j<=k;j++){
				if(all[j]==m+1){
					flag=0;
					break;
				}
				st=max(st,all[j]);
			}
			
			if(flag){
				ans+=m-st+1;
			}
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
