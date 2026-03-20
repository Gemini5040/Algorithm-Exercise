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
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> dp1(n,0),dp2(n,0);
	for(int i=0;i<n;i++){
		dp1[i]=1;
		for(int j=0;j<i;j++){
			if(a[i]>a[j]) dp1[i]=max(dp1[i],dp1[j]+1);
		}
	}
	for(int i=n-1;i>=0;i--){
		dp2[i]=1;
		for(int j=n-1;j>i;j--){
			if(a[i]>a[j]) dp2[i]=max(dp2[i],dp2[j]+1);
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans=max({ans,dp1[i]+dp2[i]-1});
	}
	cout<<ans<<endl;
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
