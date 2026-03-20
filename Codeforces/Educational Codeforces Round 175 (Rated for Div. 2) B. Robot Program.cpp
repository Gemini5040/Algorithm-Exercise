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
		ll n,x,k;
		string s;
		cin>>n>>x>>k>>s;
		
		vector<ll> a(n+1,0);
		ll p0=LONG_LONG_MAX,px=LONG_LONG_MAX;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='L') a[i]=a[i-1]-1;
			else if(s[i-1]=='R') a[i]=a[i-1]+1;
			if(p0==LONG_LONG_MAX&&a[i]==0) p0=i;
			if(px==LONG_LONG_MAX&&a[i]==-x) px=i;
		}
		
		if(p0!=LONG_LONG_MAX&&px==LONG_LONG_MAX){
			cout<<0<<"\n";
		}else if(p0==LONG_LONG_MAX&&px!=LONG_LONG_MAX){
			cout<<1<<"\n";
		}else if(p0==LONG_LONG_MAX&&px==LONG_LONG_MAX){
			cout<<0<<"\n";
		}else{
			k-=px;
			k/=p0;
			cout<<k+1<<"\n";
		}
	}
	
	return 0;
}
