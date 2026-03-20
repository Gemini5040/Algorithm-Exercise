#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,k;
		cin>>n>>k;
		if(k%2==0){
		int jj=k/2;
			if(n-1>=jj){
				int p=n/(4*jj);
				int q=n%(4*jj);
				
				long long ans=4LL*jj*p*p+q*p*2LL;
				if(q-1>=jj){
					long long cnt=q-jj;
					if(q+jj>4LL*jj) cnt+=q+jj-4LL*jj;
					ans+=cnt;
				}
				cout<<ans<<"\n";
			}
			else cout<<"0"<<"\n";
		}else{
			cout<<"0"<<"\n";
		}
	}
	
	return 0;
}