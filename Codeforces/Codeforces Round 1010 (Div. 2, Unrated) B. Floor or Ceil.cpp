#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll F(ll x,ll n){
	while(n--){
		if(x==0) return x;
		x=(x>>1);
	}
	return x;
}

ll C(ll x,ll n){
	while(n--){
		if(x<=1) return x;
		x=((x+1)>>1);
	}
	return x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		ll x,n,m;
		cin>>x>>n>>m;
		cout<<F(C(x,m),n)<<" "<<C(F(x,n),m)<<"\n";
	}
	
	return 0;
}
