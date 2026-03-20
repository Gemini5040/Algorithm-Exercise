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
		int n,k;
		cin>>n>>k;
		
		vector<ll> a(n);
		for(auto &x:a) cin>>x;
		
		ll ans=0;
		if(k==1){
			if(a[0]>a[n-1]){
				ll tmp=*max_element(a.begin()+1,a.end());
				ans=a[0]+tmp;
			}else{
				ll tmp=*max_element(a.begin(),a.end()-1);
				ans=a[n-1]+tmp;
			}
		}else if(k>1){
			vector<ll> b=a;
			sort(b.begin(),b.end(),[&](int x,int y){return x>y;});
			for(int i=0;i<=k;i++){
				ans=1LL*ans+b[i];
			}
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
