#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll P=1e9+7;
const ull H=1e9+7;
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int N=100010;

mt19937 eng(chrono::steady_clock::now().time_since_epoch().count());
ull rnd(ull l=0ull,ull r=-1ull){return uniform_int_distribution<ull>(l,r)(eng);}

void solve(){
	ll n,m;
    cin>>n>>m;
    n=n*(n-1)%MOD;
    ll k=n,r=1,ans=1;
    for(ll i=1;i<=m;i++){
        ll t=MOD-2,e=i;
        while(t){
            if(t%2) r=r*e%MOD;
            t=t/2;
            e=e*e%MOD;
        }
        ans=(ans+k*r)%MOD;
        k=k*(n+i)%MOD;
    }
    cout<<ans<<"\n";
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
