 #include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T=1;
//	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		
		vector<vector<vector<ll>>> cnt(33,vector<vector<ll>>(2,vector<ll>(2,0)));
		ll x;
		for(int i=0;i<n;i++){
			cin>>x;
			for(int j=0,k=0;j<33;j++){
				if((x>>j)&1){
					cnt[j][1][k]++;
					k=(k+1)%2;
				}else{
					cnt[j][0][k]++;
				}
			}
		}
		
		ll ans=0;
		for(int i=0;i<33;i++){
			for(int j=0;j<2;j++){
				ans+=(cnt[i][0][j]*cnt[i][1][j])<<i;
			}
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
