#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	vector<int> w(n);
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>w[i];
		sum+=w[i];
	}
	
	vector<bool> dp(sum*2+1,false);
	dp[sum]=true;
	for(auto w:w){
		vector<bool> tmp=dp;
		for(int i=0;i<=sum*2;i++){
			if(tmp[i]){
				if(i+w<=sum*2){
					dp[i+w]=true;
				}
				if(i-w>=0){
					dp[i-w]=true;
				}
			}
		}
	}
	
	int ans=0;
	for(int i=sum+1;i<=sum*2;i++){
		if(dp[i]){
			ans++;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}