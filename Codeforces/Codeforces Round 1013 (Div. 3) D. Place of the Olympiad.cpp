#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		int num=k/n;
		if(k%n) num++;
		int sp=m-num;
		int ans=num/(sp+1);
		if(num%(sp+1)) ans++;
		cout<<ans<<"\n";
	}
	
	return 0;
}