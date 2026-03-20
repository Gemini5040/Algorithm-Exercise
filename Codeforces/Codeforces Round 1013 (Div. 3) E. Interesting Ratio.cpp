#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=10000010;
int primes[N];
bool st[N];
int cnt;
int c[N];

void get_primes(int n){
	c[1]=0;
	for(int i=2;i<=n;i++){
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]<=n/i;j++){
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
		c[i]=cnt;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	get_primes(10000000);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		ll ans=0;
		for(int i=1;i<=n/2;i++){
			ans=(1LL*ans+c[n/i]);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}