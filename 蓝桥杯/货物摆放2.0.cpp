#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

ll mulmod(ll a,ll b,ll mod){
	ll res=0;
	a%=mod;
	while(b){
		if(b&1) res=(res+a)%mod;
		a=(a<<1)%mod;
		b>>=1;
	}
	return res;
}

ll powmod(ll a,ll e,ll mod){
	ll res=1;
	a%=mod;
	while(e){
		if(e&1) res=mulmod(res,a,mod);
		a=mulmod(a,a,mod);
		e>>=1;
	}
	return res;
}

bool is_prime(ll n){
	if(n<2) return false;
	if(n==2||n==3) return true;
	if(n%2==0) return false;
	
	ll d=n-1;
	int s=0;
	while(d%2==0){
		d/=2;
		s++;
	}
	
	ll bases[]={2,3,5,7,11,13,17,19,23,29,31,37};
	for(ll a:bases){
		if(a>=n) continue;
		ll x=powmod(a,d,n);
		if(x==1||x==n-1) continue;
		for(int j=0;j<s-1;j++){
			x=mulmod(x,x,n);
			if(x==n-1) break;
		}
		if(x!=n-1) return false;
	}
	return true;
}

ll pollards_rho(ll n){
	if(n%2==0) return 2;
	if(n%3==0) return 3;
	if(n%5==0) return 5;
	
	ll x=rand()%(n-2)+2;
	ll y=x;
	ll c=rand()%(n-1)+1;
	ll d=1;
	
	auto f=[&](ll x){
		return (mulmod(x,x,n)+c)%n;
	};
	
	while(d==1){
		x=f(x);
		y=f(f(y));
		d=gcd(abs(x-y),n);
	}
	return d==n?pollards_rho(n):d;
}

void factorize(ll n,map<ll,int>& factors){
	if(n==1) return;
	if(is_prime(n)){
		factors[n]++;
		return;
	}
	ll d=pollards_rho(n);
	factorize(d,factors);
	factorize(n/d,factors);
}

int main(){
	ll n=2021041820210418LL;
	map<ll,int> factors;
	factorize(n,factors);
	
	ll result=1;
	for(auto& [p,cnt]:factors){
		result*=(cnt+2)*(cnt+1)/2;
	}
	
	cout<<result<<endl;
	
	return 0;
}