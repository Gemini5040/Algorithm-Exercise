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
		int n;
		ll k;
		string s;
		cin>>n>>k>>s;
		
		vector<ll> a(n);
		for(auto &x:a) cin>>x;
		
		int pos=-1;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				pos=i;
				a[i]=-1e13;
			}
		}
		
		ll ma=0,cur=0;
		for(int i=0;i<n;i++){
			cur=max(cur+a[i],a[i]);
			ma=max(ma,cur);
		}
		
		if(ma>k||(ma<k&&pos==-1)){
			cout<<"NO"<<"\n";
			continue;
		}
		
		if(pos!=-1){
			ma=0,cur=0;
			for(int i=pos-1;i>=0;i--){
				cur+=a[i];
				ma=max(ma,cur);
			}
			ll L=ma;
			
			ma=0,cur=0;
			for(int i=pos+1;i<n;i++){
				cur+=a[i];
				ma=max(ma,cur);
			}
			ll R=ma;
			
			a[pos]=k-L-R;
		}
		
		cout<<"YES"<<"\n";
		for(int i=0;i<n;i++){
			cout<<a[i]<<" \n"[i==n-1];
		}
	}
	
	return 0;
}
