#include <bits/stdc++.h>
using namespace std;

const int N=1010;
int dp[N];

int dfs(int n){
	if(n==0) return 0;
	if(dp[n]) return dp[n];
	int ne=n>>1;
	int sum=ne;
	for(int i=1;i<=ne;i++){
		sum+=dfs(i);
	}
	return dp[n]=sum;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	dfs(n);
	cout<<dp[n]+1<<"\n";
	
	return 0;
}
