#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	vector<ll> dp(4,0);
	for(int i=1;i<=2023;i++){
		s+=to_string(i);
	}
	for(int i=0;i<(int)s.size();i++){
		if(s[i]=='2'){
			dp[0]++;
			dp[2]+=dp[1];
		}
		if(s[i]=='0'){
			dp[1]+=dp[0];
		}
		if(s[i]=='3'){
			dp[3]+=dp[2];
		}
	}
	
	cout<<dp[3];
	
	return 0;
}
