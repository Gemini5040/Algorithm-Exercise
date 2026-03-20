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
		ll n,m;
		cin>>n>>m;
		
		vector<ll> a(m);
		for(auto &x:a) cin>>x;
		sort(a.begin(),a.end(),[&](ll x,ll y){return x<y;});
		
		ll ans=0;
		for(int i=1;i<=n-1;i++){
			auto it_x=lower_bound(a.begin(),a.end(),i);
			ll x=m-(it_x-a.begin());
			
			ll target=n-i;
			auto it_y=lower_bound(a.begin(),a.end(),target);
			ll y=m-(it_y-a.begin());
			
			ans+=x*y-min(x,y);
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
