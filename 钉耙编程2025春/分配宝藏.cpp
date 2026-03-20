#include <iostream>
using namespace std;

const int MOD=1000000007;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		
		n/=2;
		long long ans=1LL*n*(n+1)%MOD;
		
		cout<<ans<<"\n";
	}
	
	return 0;
}