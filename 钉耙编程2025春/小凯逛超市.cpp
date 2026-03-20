#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod=1e9+7;
const int N=410;
int g[N];
ll dp[N][N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		fill(&dp[0][0],&dp[0][0]+N*N,0);
		
		int n,m,v;
		cin>>n>>m>>v;
		
		for(int i=1;i<=n;i++){
			cin>>g[i];
		}

		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=g[i];k<=v;k++){
					dp[j][k]=(dp[j][k]+dp[j-1][k-g[i]])%mod;
				}
			}
		}
		
		ll ans=0;
		for(int i=1;i<=v;i++){
			ans=(ans+dp[m][i])%mod;
		}
		cout<<ans<<"\n";
	}
		
	return 0;
}