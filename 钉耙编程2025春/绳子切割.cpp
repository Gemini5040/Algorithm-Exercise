#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,m;
		cin>>n>>m;
		
		vector<int> a(n+1,0);
		for(int i=1;i<=m;i++){
			int u,v;
			cin>>u>>v;
			if(u>v) u^=v^=u^=v;
			a[v]=1;
		}
		
		int flag=1;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				flag=0;
				break;
			}
		}
		
		cout<<flag<<"\n";
	}
	
	return 0;
}
