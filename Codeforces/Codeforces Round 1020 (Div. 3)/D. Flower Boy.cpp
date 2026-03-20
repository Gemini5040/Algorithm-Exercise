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
		
		vector<int> a(n+1),b(m+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>b[i];
		}
		
		int p=1;
		for(int i=1;i<=n&&p<=m;i++){
			if(a[i]>=b[p]) p++;
		}
		
		if(p==m+1){
			cout<<0<<"\n";
			continue;
		}
		
		vector<int> pre(n+1,0),suf(n+2,0);
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1];
			if(a[i]>=b[pre[i]+1]){
				pre[i]++;
			}
		}
		for(int i=n;i>=1;i--){
			suf[i]=suf[i+1];
			if(a[i]>=b[m-suf[i]]){
				suf[i]++;
			}
		}
		
		int ans=INT_MAX;
		for(int i=0;i<=n;i++){
			if(pre[i]+suf[i+1]==m-1){
				ans=min(ans,b[pre[i]+1]);
			}
		}
		
//		cout<<"\n**************\n";
//		for(int i=1;i<=n;i++){
//			cout<<pre[i]<<" ";
//		}
//		cout<<"\n";
//		for(int i=1;i<=n;i++){
//			cout<<suf[i]<<" ";
//		}
//		cout<<"\n**************\n";
		
		if(ans==INT_MAX) cout<<-1<<"\n";
		else cout<<ans<<"\n";
	}
	
	return 0;
}
