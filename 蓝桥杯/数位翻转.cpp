#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll rev(ll x){
	ll res=0;
	while(x){
		res=((res<<1)|(x&1));
		x>>=1;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	vector<ll> a(n);
	ll sum=0;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		sum+=x;
		a[i]=rev(x)-x;
	}
	
	vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(m+1,vector<ll>(2,0)));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
			dp[i][j][1]=max(dp[i-1][j-1][0],dp[i-1][j][1])+a[i-1];
		}
	}
	
	cout<<sum+max(dp[n][m][0],dp[n][m][1])<<"\n";
	
	return 0;
}
