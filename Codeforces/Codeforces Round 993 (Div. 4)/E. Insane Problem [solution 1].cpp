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
		ll k,l1,r1,l2,r2;
		cin>>k>>l1>>r1>>l2>>r2;
		ll ans=0;
		ll kn=1LL;
		for(ll n=0;r2/kn>=l1;n++){
			ans+=max(0LL,min(r2/kn,r1)-max((l2-1)/kn+1,l1)+1LL);
			kn*=k;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}