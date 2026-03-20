#include <bits/stdc++.h>
using namespace std;

const int mod=100003;
const int N=100010;

int dp[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	dp[0]=1;
	for(int i=1;i<=n;i++){
		int limit=min(m,i);
		for(int j=1;j<=limit;j++){
			dp[i]=(dp[i]+dp[i-j])%mod;
		}
	}
	
	cout<<dp[n]<<"\n";
	
	return 0;
}
