#include <bits/stdc++.h>
using namespace std;

const int N=55;
int g[N][N];
int st[N][N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		fill(&g[0][0],&g[0][0]+N*N,0);
		fill(&st[0][0],&st[0][0]+N*N,0);
		
		int n,m;
		cin>>n>>m;
		
		string s;
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=1;j<=m;j++){
				g[i][j]=s[j-1]-'0';
			}
		}
		
		for(int i=1;i<=n;i++){
			if(g[i][1]){
				st[i][1]=1;
				for(int j=2;j<=m;j++){
					if(!g[i][j]) break;
					st[i][j]=1;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(g[1][j]){
				st[1][j]=1;
				for(int i=2;i<=n;i++){
					if(!g[i][j]) break;
					st[i][j]=1;
				}
			}
		}
		
		int flag=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(st[i][j]!=g[i][j]){
					flag=0;
					break;
				}
			}
			if(!flag){
				break;
			}
		}
		
		if(flag) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
	
	return 0;
}