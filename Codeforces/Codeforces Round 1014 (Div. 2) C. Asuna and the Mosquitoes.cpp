#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		ll ma=0;
		ll sum=0;
		int odd=0;
		for(int i=1;i<=n;i++){
			ll t;
			cin>>t;
			ma=max(ma,t);
			sum+=t;
			if((t>>0&1)==1) odd++;
		}
		
		if(odd==0||n-odd==0){
			cout<<ma<<"\n";
		}else{
			cout<<sum-odd+1<<"\n";
		}
	}
	
	return 0;
}