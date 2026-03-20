#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll x){
	ll r=sqrt(x);
	return r*r==x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		ll n;
		cin>>n;
		
		ll s=n*(n+1)/2;
		if(check(s)){
			cout<<-1<<"\n";
		}else{
			vector<ll> ans(n+1);
			for(int i=1;i<=n;i++) ans[i]=i;
			for(int i=1;i<=n;i++){
				ll t=1LL*i*(i+1)/2;
				if(check(t)) swap(ans[i],ans[i+1]);
				cout<<ans[i]<<" \n"[i==n];
			}
		}
	}
	
	return 0;
}
