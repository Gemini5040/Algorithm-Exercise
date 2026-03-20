#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_prime(ll x){
	if(x<2) return false;
	for(ll i=2;i<=x/i;i++){
		if(x%i==0) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		ll n,k;
		cin>>n>>k;
		if((is_prime(n)&&k==1)||(n==1&&k==2)){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}
	
	return 0;
}
