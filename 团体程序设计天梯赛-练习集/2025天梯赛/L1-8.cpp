#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll INF=0x3f3f3f3f3f3f3f3f;
ll g[1010][1010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
		}
	}
	
	while(k--){
		ll ma=-INF;
		int x=0,y=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(g[i][j]>ma){
					ma=g[i][j];
					x=i,y=j;
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			g[i][y]=-INF;
		}
		for(int i=1;i<=m;i++){
			g[x][i]=-INF;
		}
	}
	
	for(int i=1;i<=n;i++){
		int fg=0;
		int have=0;
		for(int j=1;j<=m;j++){
			if(g[i][j]!=-INF){
				have=1;
				if(fg) cout<<" ";
				cout<<g[i][j];
				fg=1;
			}
		}
		if(have) cout<<"\n";
	}
	
	return 0;
}
