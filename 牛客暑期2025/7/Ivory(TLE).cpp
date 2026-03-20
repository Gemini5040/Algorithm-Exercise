#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;

const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll P=1e9+7;
const ull H=1e9+7;
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int N=110;

mt19937 eng(chrono::steady_clock::now().time_since_epoch().count());
ull rnd(ull l=0ull,ull r=-1ull){return uniform_int_distribution<ull>(l,r)(eng);}

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

ll mult_mod(ll a,ll b,ll n){
	a%=n,b%=n;
	ll ret=0;
	while(b){
		if(b&1){
			ret+=a;
			if(ret>=n) ret-=n;
		}
		a<<=1;
		if(a>=n) a-=n;
		b>>=1;
	}
	return ret;
}

ll Base(ll x,ll y,ll n){
	ll ret=1;
	while(y){
		if(y&1LL) ret=mult_mod(ret,x,n);
		x=mult_mod(x,x,n);
		y>>=1;
	}
	return ret;
}

vector<ll> X(N);
bool miller_rabin(ll n){
	if(n==2) return true;
	
	ll s=20,t=0,u=n-1;
	while(!(u&1)){
		t++;
		u>>=1;
	}
	
	while(s--){
		ll a=rand()%(n-1)+1;
		X[0]=Base(a,u,n);
		for(ll i=1;i<=t;i++){
			X[i]=mult_mod(X[i-1],X[i-1],n);
			if(X[i]==1&&X[i-1]!=1&&X[i-1]!=(n-1)){
				return false;
			}
		}
		if(X[t]!=1){
			return false;
		}
	}
	
	return true;
}

ll pollard_rho(ll n){
	ll i=1,k=2;
	ll c=rand()%(n-1)+1;
	ll x=rand()%n;
	ll y=x;
	while(true){
		i++;
		x=(mult_mod(x,x,n)+c)%n;
		ll d=gcd(y>x?y-x:x-y,n);
		if(d!=1&&d!=n) return d;
		if(y==x) return n;
		if(i==k){
			y=x;
			k=k<<1;
		}
	}
	assert(0);
	return -1;
}

set<ll> factor;
void findfac(ll n){
	if(miller_rabin(n)){
		factor.insert(n);
		return;
	}
	ll p=n;
	while(p>=n){
		p=pollard_rho(p);
	}
	findfac(p);
	findfac(n/p);
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

void solve(){
	factor.clear();
	
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll g=gcd(a,c);
	
    if(g==1){
        cout<<1<<"\n";
        return;
    }

    findfac(g);
    vector<ll> fac;
    for(ll x:factor){
        fac.push_back(x);
    }

    vector<i128> cnt1(fac.size(),0),cnt2(fac.size(),0);
    ll ta=a,tc=c;
    for(int i=0;i<(int)fac.size();i++){
        while(ta%fac[i]==0){
            ta/=fac[i];
            cnt1[i]++;
        }
        while(tc%fac[i]==0){
            tc/=fac[i];
            cnt2[i]++;
        }
    }

    vector<i128> cnt(fac.size());
    for(int i=0;i<(int)fac.size();i++){
        cnt1[i]*=b;
        cnt2[i]*=d;
        cnt[i]=min(cnt1[i],cnt2[i]);
    }

    ll ans=1;
    for(int i=0;i<(int)fac.size();i++){
        ans=(ans*fastpow(fac[i],cnt[i]))%MOD;
    }

    cout<<ans<<"\n";
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