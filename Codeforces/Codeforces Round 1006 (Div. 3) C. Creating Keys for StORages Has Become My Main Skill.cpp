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
		int n,x;
		cin>>n>>x;
		
		vector<int> w(32,0);
		for(int i=0;i<=30;i++){
			w[i+1]=((x>>i)&1);
		}
		
		int ctn=0;
		for(int i=1;i<=31;i++){
			if(w[i]==0) break;
			else ctn++;
		}
		
		vector<int> ans;
		int mex=(1<<ctn);
		int t=0;
		if(n>mex){
			for(int i=0;i<mex;i++) ans.push_back(i);
			for(int i=0;i<n-mex;i++) ans.push_back(x);
		}else{
			for(int i=0;i<n-1;i++){
				ans.push_back(i);
				t|=i;
			}
			if(x-t==0||x-(t|(n-1))==0) ans.push_back(n-1);
			else ans.push_back(x);
		}
		
		for(int i=0;i<(int)ans.size();i++){
			cout<<ans[i]<<" \n"[i==(int)ans.size()-1];
		}
	}
	
	return 0;
}
