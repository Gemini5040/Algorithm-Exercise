#include <bits/stdc++.h>
using namespace std;

const int N=210;
int dp[N][7];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,k;
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(j==1) dp[i][j]=1;
			else if(i<j) dp[i][j]=0;
			else if(i==j) dp[i][j]=1;
			else dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
		}
	}
	
	cout<<dp[n][k]<<"\n";
	
	return 0;
}
