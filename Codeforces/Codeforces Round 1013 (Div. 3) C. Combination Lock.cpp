#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		if((n>>0&1)==0) cout<<-1<<"\n";
		else{
			for(int i=n;i>=1;i--){
				cout<<i<<" ";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}