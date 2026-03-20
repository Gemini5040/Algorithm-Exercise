#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
const int N=110;
int n,m;
int dp[N][N][N];

int dfs(int w,int p,int f){
	if(w<0||p<0||f<0) return 0;
	if(w>f) return 0;
	if(w==1&&p==0&&f==1) return 1;
	if(dp[w][p][f]!=-1) return dp[w][p][f];
	return dp[w][p][f]=(dfs(w*2,p-1,f)+dfs(w-1,p,f-1))%MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	memset(dp,-1,sizeof(dp));
	cout<<dfs(2,n,m)<<endl;
	
	return 0;
}