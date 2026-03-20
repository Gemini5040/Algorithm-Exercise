#include <bits/stdc++.h>
using namespace std;

//#define int long long
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

ll fastPow(ll a,ll n,ll mod){
	ll ans=1;
	a%=mod;
	while(n){
		if(n&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ans;
}

void solve(){
	ll n,m,k;
	cin>>n>>m>>k;
	if(n>m) swap(n,m);

	vector<ll> arr;
	for(ll i=2;i<=n+m;i++){
		arr.push_back(fastPow(i,k,P));
	}

	ll ans=0;
	for(int i=0;i<=n-2;i++){
		ans=(ans+(i+1)*arr[i])%P;
	}
	for(int i=n-1;i<=m-1;i++){
		ans=(ans+n*arr[i])%P;
	}
	for(int i=m;i<=n+m-2;i++){
		ans=(ans+(n+m-i-1)*arr[i])%P;
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
