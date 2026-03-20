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
		int n,m,p,q;
		cin>>n>>m>>p>>q;
		
		if(n%p==0){
			int cnt=n/p;
			if(q*cnt==m){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}else{
			cout<<"YES"<<"\n";
		}
	}
	
	return 0;
}
