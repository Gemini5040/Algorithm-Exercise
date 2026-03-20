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
		ll n,x;
		cin>>n>>x;
		
		if(n==1&&x==0){
			cout<<"-1"<<"\n";
			continue;
		}
		
		vector<bool> w(36,0);
		int cnt=0;
		for(int i=30;i>=0;i--){
			w[i]=((x>>i)&1);
			if(w[i]) cnt++;
		}
		
		if(cnt>=n){
			cout<<x<<"\n";
			continue;
		}
		
		ll ans=0;
		int t=n;
		for(int i=30;i>=1;i--){
			if(w[i]){
				ans+=(1<<i);
				t--;
			}
		}
		if(t<n){
			if(w[0]){
				if((t&1)==1){
					ans+=t;
				}else{
					ans+=t+1;
				}
			}else{
				if((t&1)==1){
					ans+=t+1;
				}else{
					ans+=t;
				}
			}
		}else if(t==n){
			if(w[0]){
				if((t&1)==1){
					ans+=t;
				}else{
					ans+=t+3;
				}
			}else{
				if((t&1)==1){
					ans+=t+3;
				}else{
					ans+=t;
				}
			}
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
