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
		ll n,k,x;
		cin>>n>>k>>x;
		
		vector<ll> a(n+1,0),s(n+1,0);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		reverse(a.begin()+1,a.end());
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+a[i];
		}
		
		ll cnt=x/s[n];
		cnt=min(cnt,k);
		ll ans=0;
		for(int i=0;i<=n;i++){
			if(s[i]+cnt*s[n]>=x){
				ans=k*n-(cnt*n+i)+1;
				break;
			}
		}
		if(ans<0) ans=0;
		cout<<ans<<"\n";
	}
	
	return 0;
}
