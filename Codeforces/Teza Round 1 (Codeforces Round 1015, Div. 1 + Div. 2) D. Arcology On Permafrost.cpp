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
		
		vector<int> ans;
		int t=max(n/(m+1),k);
		int num=0;
		for(int i=1;i<=n;i++){
			ans.push_back(num);
			num=(num+1)%t;
		}
		
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
