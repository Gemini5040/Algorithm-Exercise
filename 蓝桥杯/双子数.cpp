#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N=10000000;
const ll l=2333;
const ll r=23333333333333;
vector<ll> primes(N);
vector<bool> st(N,false);
ll cnt;

void get_primes(ll n){
	for(ll i=2;i<=n;i++){
		if(!st[i]) primes[cnt++]=i;
		for(ll j=0;primes[j]<=n/i;j++){
			st[i*primes[j]]=true;
			if(i%primes[j]==0) break;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	get_primes(N);
	
	ll ans=0;
	for(int i=0;i<cnt;i++){
		ll p=primes[i]*primes[i];
		if(p*p>r) break;
		for(int j=i+1;j<cnt;j++){
			ll t=primes[i]*primes[i]*primes[j]*primes[j];
			if(t>=l&&t<=r){
				ans++;
			}else if(t>r){
				break;
			}
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
