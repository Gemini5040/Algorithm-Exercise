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
		int n,m;
		cin>>n>>m;
		
		vector<ll> c(n),r(n);
		for(auto &x:c) cin>>x;
		for(auto &x:r) cin>>x;
		
		map<ll,ll> cnt;
		for(int i=0;i<n;i++){
			for(ll x=c[i]-r[i];x<=c[i]+r[i];x++){
				cnt[x]=max(cnt[x],2*(ll)sqrt(r[i]*r[i]-(x-c[i])*(x-c[i]))+1);
			}
		}
		
		ll ans=0;
		for(auto &x:cnt) ans+=x.second;
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
