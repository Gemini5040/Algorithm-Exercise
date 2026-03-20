#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"
using ll=long long;

const int inf=1e9;
const int N=300010;

void solve(){
	int n;
	cin>>n;
	vector<int> dp(n+1,inf);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		dp[a]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			dp[j]=min(dp[j],dp[i]+dp[j/i]);
		}
	}
	for(int i=1;i<=n;i++){
		if(dp[i]==1e9){
			dp[i]=-1;
		}
		cout<<dp[i]<<" \n"[i==n];
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T=1;
	cin>>T;

	while(T--){
		solve();
	}

	return 0;
}