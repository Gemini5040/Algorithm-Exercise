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
		ll n,k;
		cin>>n>>k;
		ll t=k%n;
		if(t==0){
			cout<<0<<"\n";
			continue;
		}
		if(((n-t)&1)==0){
			cout<<(n-t)/2<<"\n";
			continue;
		}else if((n&1)==1){
			cout<<(n-t+1)/2+n/2<<"\n";
			continue;
		}
		cout<<-1<<"\n";
	}
	
	return 0;
}
