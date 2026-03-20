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
		int n;
		cin>>n;
		
		vector<ll> a(n+1,0);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
		vector<ll> pre(n+1,0),suf(n+2,0);
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1];
			if(a[i]>=0){
				pre[i]+=a[i];
			}
		}
		for(int i=n;i>=1;i--){
			suf[i]=suf[i+1];
			if(a[i]<0){
				suf[i]-=a[i];
			}
		}
		
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,pre[i]+suf[i]);
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
