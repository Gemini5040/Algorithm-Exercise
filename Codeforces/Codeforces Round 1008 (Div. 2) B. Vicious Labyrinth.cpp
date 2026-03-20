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
		int n,k;
		cin>>n>>k;
		
		vector<int> ans;
		if((k&1)==1){
			for(int i=1;i<=n;i++){
				ans.push_back(n-(i==n));
			}
		}else{
			for(int i=1;i<=n;i++){
				ans.push_back(n-(i!=n-1));
			}
		}
		
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" \n"[i==n-1];
		}
	}
	
	return 0;
}
