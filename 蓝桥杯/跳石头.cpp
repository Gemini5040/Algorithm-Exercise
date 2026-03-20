#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=40010;
bitset<N> dp[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	vector<int> c(n);
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	
	int ans=0;
	for(int i=n;i>=1;i--){
		if(i+c[i-1]<=n){
			dp[i]|=dp[i+c[i-1]];
		}
		if(i*2<=n){
			dp[i]|=dp[i*2];
		}
		dp[i].set(c[i-1]-1);
		ans=max(ans,(int)dp[i].count());
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
