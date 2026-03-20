#include <bits/stdc++.h>
using namespace std;

int a[10010];
int dp[10010];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		
		string s,k_str;
		cin>>s>>k_str;
		int size=s.size();
		int k_size=k_str.size();
		k_size=min(k_size,3);
		
		int k=0;
		for(int i=0;i<k_size;i++){
			k=k*10+k_str[i]-'0';
		}
		
		string ss=s;
		int times=min(size,k);
		for(int i=1;i<times;i++){
			s+=ss;
		}
		size=s.size();
		
		for(int i=0;i<size;i++){
			a[i+1]=(int)s[i];
		}
		
		for(int i=1;i<=size;i++){
			dp[i]=1;
			for(int j=1;j<i;j++){
				if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+1);
			}
		}
		
		int res=0;
		for(int i=1;i<=size;i++){
			res=max(res,dp[i]);
		}
		
		cout<<res<<endl;
	}
	
	return 0;
}