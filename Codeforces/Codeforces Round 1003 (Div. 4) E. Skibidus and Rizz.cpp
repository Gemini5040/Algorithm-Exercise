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
		int n,m,k;
		cin>>n>>m>>k;
		
		if((int)abs(n-m)>k||(k>n&&k>m)){
			cout<<-1<<"\n";
		}else{
			vector<int> ans;
			int tn=n/k*k,tm=m/k*k;
			int lim=n/k+m/k;
			int flag=(tm>tn)||(tm==tn&&(m%k)>(n%k));
			for(int i=1;i<=lim;i++){
				for(int j=1;j<=k;j++){
					ans.push_back(flag);
				}
				flag=1-flag;
			}
			if(!flag){
				for(int i=1;i<=n%k;i++){
					ans.push_back(flag);
				}
				flag=1-flag;
				for(int i=1;i<=m%k;i++){
					ans.push_back(flag);
				}
			}else{
				for(int i=1;i<=m%k;i++){
					ans.push_back(flag);
				}
				flag=1-flag;
				for(int i=1;i<=n%k;i++){
					ans.push_back(flag);
				}
			}
			for(int i=0;i<n+m;i++){
				cout<<ans[i];
			}
			cout<<"\n";
		}
	}
	
	return 0;
}
