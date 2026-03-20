#include <bits/stdc++.h>
using namespace std;

const int N=810;
const int M=1610;
int g[N][N];
int st[M];
int ans[M];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		fill(&g[0][0],&g[0][0]+N*N,0);
		fill(st,st+M,0);
		fill(ans,ans+M,0);
		
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>g[i][j];
			}
		}
		
		int p=2;
		for(int i=1;i<n;i++){
			st[g[1][i]]=1;
			ans[p++]=g[1][i];
		}
		for(int i=1;i<=n;i++){
			st[g[n][i]]=1;
			ans[p++]=g[n][i];
		}
		
		for(int i=1;i<=n*2;i++){
			if(!st[i]){
				ans[1]=i;
				break;
			}
		}
		
		for(int i=1;i<p;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}