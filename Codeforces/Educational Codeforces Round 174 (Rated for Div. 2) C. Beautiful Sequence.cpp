#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod=998244353;

int add(int x,int y){
	if((x+y)>=0) return (x+y)%mod;
	else return (x+y)%mod+mod;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		
		vector<int> dp(4,0);
		dp[0]=1;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(x==2) dp[x]=add(dp[x],dp[x]);
			dp[x]=add(dp[x],dp[x-1]);
		}
		
		cout<<dp[3]<<"\n";
	}
	
	return 0;
}
