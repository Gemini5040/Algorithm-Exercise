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
		ll k;
		cin>>n>>k;
		
		vector<ll> a(n+1,0);
		ll mi=1e9,ma=0;
		ll sum=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==ma){
				cnt++;
			}else if(a[i]>ma){
				ma=a[i];
				cnt=1;
			}
			mi=min(mi,a[i]);
			sum+=a[i];
		}
		
		if(ma-mi>k&&ma-mi-1<=k&&cnt==1){
			if((sum&1)==1){
				cout<<"Tom"<<"\n";
			}else{
				cout<<"Jerry"<<"\n";
			}
		}else if(ma-mi>k&&ma-mi-1<=k&&cnt>1){
			cout<<"Jerry"<<"\n";
		}else if(ma-mi<=k){
			if((sum&1)==1){
				cout<<"Tom"<<"\n";
			}else{
				cout<<"Jerry"<<"\n";
			}
		}else if(ma-mi-1>k){
			cout<<"Jerry"<<"\n";
		}
	}
	
	return 0;
}
