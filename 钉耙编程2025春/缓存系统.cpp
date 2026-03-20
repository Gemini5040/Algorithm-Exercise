#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=110;
const int X=5010;
ll sp[N][N],v[N][N];
ll dp[N][X];
int pos;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		fill(&sp[0][0],&sp[0][0]+N*N,0);
		fill(&v[0][0],&v[0][0]+N*N,0);
		fill(&dp[0][0],&dp[0][0]+N*X,0);
		
		int n,m,x;
		cin>>n>>m>>x;
		
		ll sum_v=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>sp[i][j]>>v[i][j];
				sum_v+=v[i][j];
				sp[i][j]+=sp[i][j-1];
				v[i][j]+=v[i][j-1];
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=x;j++){
				dp[i][j]=dp[i-1][j];
				for(int k=1;k<=m;k++){
					if(j>=sp[i][k]) dp[i][j]=max(dp[i][j],dp[i-1][j-sp[i][k]]+v[i][k]);
				}
			}
		}
		
		ll ans=sum_v-dp[n][x];
		cout<<ans<<"\n";
	}
	
	return 0;
}
