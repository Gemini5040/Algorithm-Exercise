#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		ll a,b,c,k;
		cin>>a>>b>>c>>k;
		k=min(k,500LL);
		for(int i=1;i<=k;i++){
			ll ta=a,tb=b,tc=c;
			a=(tb+tc)>>1;
			b=(ta+tc)>>1;
			c=(ta+tb)>>1;
		}
		cout<<a<<" "<<b<<" "<<c<<"\n";
	}
	
	return 0;
}