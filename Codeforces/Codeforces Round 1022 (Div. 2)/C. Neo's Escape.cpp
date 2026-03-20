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
		
		vector<int> a;
		a.push_back(-1e9);
		for(int i=1;i<=n;i++){
			int t;
			cin>>t;
			if(t!=a.back()) a.push_back(t);
		}
		a.push_back(-1e9);
		
		int ans=0;
		for(int i=1;i<=(int)a.size()-1;i++){
			if(a[i]>a[i-1]&&a[i]>a[i+1]) ans++;
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
