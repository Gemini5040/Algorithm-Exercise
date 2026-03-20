#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl "\n"
using ll=long long;
using ull=unsigned long long;
using i128=__int128;

const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll inv2=(MOD+1)/2;
const ll P=1e9+7;
const ull H=1e9+7;
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int N=100010;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ull rnd(ull l=0ull,ull r=-1ull){return uniform_int_distribution<ull>(l,r)(rng);}

void solve(){
	int m,n;
	cin>>m>>n;
	vector<vector<int>> g(m+1,vector<int>(n+1,0));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	vector<vector<vector<int>>> dp(m+n+1,vector<vector<int>>(n+1,vector<int>(n+1,0)));
	for(int k=2;k<=m+n;k++){
		for(int j1=1;j1<=n&&j1<=k-1;j1++){
			for(int j2=1;j2<=n&&j2<=k-1;j2++){
				int i1=k-j1,i2=k-j2;
				if(!(i1>=1&&i1<=m&&i2>=1&&i2<=m)) continue;
				if(i1==i2&&k!=2&&k!=m+n) dp[k][j1][j2]=max({dp[k-1][j1][j2],dp[k-1][j1-1][j2],dp[k-1][j1][j2-1],dp[k-1][j1-1][j2-1]})+g[i1][j1];
				else dp[k][j1][j2]=max({dp[k-1][j1][j2],dp[k-1][j1-1][j2],dp[k-1][j1][j2-1],dp[k-1][j1-1][j2-1]})+g[i1][j1]+g[i2][j2];
			}
		}
	}
	cout<<dp[m+n][n][n]<<endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T=1;
	// cin>>T;
	
	while(T--){
		solve();
	}
	
	return 0;
}
