#include <bits/stdc++.h>
using namespace std;

int a[110],b[110];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		fill(a,a+110,0);
		fill(b,b+110,0);
		
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[a[i]]=1;
		}
		
		int ans=0;
		for(int i=1;i<=100;i++){
			if(b[i]) ans++;
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
