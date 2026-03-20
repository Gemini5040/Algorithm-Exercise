#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		int ans1=0,ans2=1,y=0;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			ans1=(ans1+1LL*y*x%mod)%mod;
			if(i<n) ans2=(1LL*ans2*((1LL*(n-i+1)*(n-i)/2)%mod))%mod;
			y=(y+x)%mod;
		}
		cout<<ans1<<" "<<ans2<<"\n";
	}
	
	return 0;
}