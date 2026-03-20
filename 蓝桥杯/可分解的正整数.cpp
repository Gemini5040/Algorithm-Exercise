#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	
	int ans=0;
	
	int a;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a>1) ans++;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}