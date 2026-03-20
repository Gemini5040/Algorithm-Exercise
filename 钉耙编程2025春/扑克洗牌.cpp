#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		
		vector<int> a(n+1,0),dp(n+1,0);
		
		int ma=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dp[a[i]]=dp[a[i]-1]+1;
			ma=max(ma,dp[a[i]]);
		}
		
		cout<<n-ma<<"\n";
	}
	
	return 0;
}
