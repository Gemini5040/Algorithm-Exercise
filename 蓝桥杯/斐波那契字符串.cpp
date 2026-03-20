#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=100010;
const int mod=1e9+7;
string s[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	s[0]="0";
	s[1]="0";
	s[2]="1";
	
	vector<vector<ll>> cnt(N,vector<ll>(2,0));
	cnt[1][0]=1,cnt[2][1]=1;
	for(int i=3;i<N;i++){
		cnt[i][0]=(cnt[i-2][0]+cnt[i-1][0])%mod;
		cnt[i][1]=(cnt[i-2][1]+cnt[i-1][1])%mod;
	}
	vector<ll> dp(N,0);
	dp[1]=0,dp[2]=0,dp[3]=0,dp[4]=1,dp[5]=2;
	for(int i=6;i<N;i++){
		dp[i]=(dp[i-2]+dp[i-1]+cnt[i-2][1]*cnt[i-1][0]%mod)%mod;
	}
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		
		cout<<dp[n]<<"\n";
	}
	
	return 0;
}
