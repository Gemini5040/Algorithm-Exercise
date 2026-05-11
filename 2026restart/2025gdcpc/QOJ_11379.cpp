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
const int N=1e6+5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ull rnd(ull l=0ull,ull r=-1ull){return uniform_int_distribution<ull>(l,r)(rng);}

ll num[N],sub[N];
ll f[N];
ll a[N];
ll qs[N];
void solve(){
	ll n,q;
	cin>>n>>q;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=q;i++)
		cin>>qs[i];
	ll mx=0;
	for(ll i=1;i<=a[n];i++)
	{
		ll j=upper_bound(a+1,a+n+1,i)-a-1;
		f[i]=i/(a[j])+f[i%a[j]];
		mx=max(mx,f[i]);
		num[f[i]]++;
		//cout<<i<<" "<<f[i]<<endl;
	}
	for(ll i=1;i<=mx;i++)
	{
		sub[i]=sub[i-1]+num[i];
	}
	for(ll i=1;i<=q;i++)
	{
		if(qs[i]>=mx) cout<<sub[mx]<<" ";
		else cout<<sub[qs[i]]<<" ";
	}

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
