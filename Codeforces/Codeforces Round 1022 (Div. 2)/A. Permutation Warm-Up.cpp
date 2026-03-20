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
		
		int m=n>>1;
		int s=0;
		if((n&1)==1){
			s=(2*m+m*(m-1))*2;
		}else{
			s=(1*m+m*(m-1))*2;
		}
		
		int ans=(s+2)>>1;
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
