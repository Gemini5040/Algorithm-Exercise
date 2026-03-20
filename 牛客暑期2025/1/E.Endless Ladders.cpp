#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		ll a,b;
		cin>>a>>b;
		if(a<b) swap(a,b);
		ll t=a*a-b*b;
		if(t==3){
			cout<<1<<"\n";
		}else if(t==5){
			cout<<2<<"\n";
		}else{
			ll n=(t+2)/4;
			cout<<t-n-2<<"\n";
		}
	}
	
	return 0;
}
