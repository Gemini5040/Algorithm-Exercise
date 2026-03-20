#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int m,a,b,c;
		cin>>m>>a>>b>>c;
		
		int ans=0;
		int spare1=m-a,spare2=m-b;
		if(spare1>0){
			ans+=a;
			ans+=min(c,spare1);
			c-=min(c,spare1);
		}else{
			ans+=m;
		}
		if(spare2>0){
			ans+=b;
			ans+=min(c,spare2);
		}else{
			ans+=m;
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}