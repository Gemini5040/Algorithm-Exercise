#include <bits/stdc++.h>
using namespace std;

//#define int long long
using ll=long long;
using ull=unsigned long long;
using i128=__int128;

const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll P=1e9+7;
const ull H=1e9+7;
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int N=100010;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ull rnd(ull l=0ull,ull r=-1ull){return uniform_int_distribution<ull>(l,r)(rng);}

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

ll fastpow(ll a,i128 n){
	ll ans=1;
	a%=MOD;
	while(n>0){
		if(n&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		n>>=1;
	}
	return ans;
}

ll cal(ll a,ll b,ll c,ll d){
	ll g=gcd(a,c);
	if(g==1||b==0||d==0){
		return 1;
	}
	i128 ka=0,kc=0;
	while(a%g==0){
		a/=g;
		ka++;
	}
	while(c%g==0){
		c/=g;
		kc++;
	}
	ka*=b,kc*=d;
	if(ka>kc){
		swap(a,c);
		swap(b,d);
		swap(ka,kc);
	}
	return fastpow(g,ka)*cal(a,b,g,kc-ka)%MOD;
}

void solve(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<cal(a,b,c,d)<<"\n";
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