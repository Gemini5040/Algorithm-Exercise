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
	int n;
	cin>>n;
	vector<vector<int>> g(n+1,vector<int>(n+1,0));
	int x,y,num;
	while((cin>>x>>y>>num)&&x&&y&&num){
		g[x][y]=num;
	}
	vector<vector<vector<int>>> dp(2*n+1,vector<vector<int>>(n+1,vector<int>(n+1,0)));
	for(int k=2;k<=2*n;k++){
		for(int i1=1;i1<=n&&i1<=k-1;i1++){
			for(int i2=1;i2<=n&&i2<=k-1;i2++){
				int j1=k-i1,j2=k-i2;
				dp[k][i1][i2]=max({dp[k-1][i1-1][i2-1],dp[k-1][i1-1][i2],dp[k-1][i1][i2-1],dp[k-1][i1][i2]})+g[i1][j1];
				if(i1!=i2){
					dp[k][i1][i2]+=g[i2][j2];
				}
			}
		}
	}
	cout<<dp[2*n][n][n]<<endl;
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
