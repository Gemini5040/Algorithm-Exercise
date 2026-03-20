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
		ll n,m;
		cin>>n>>m;
		vector<vector<ll>> a(n+10,vector<ll>(m+10,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				a[i][0]+=a[i][j];
			}
		}
		sort(a.begin()+1,a.begin()+1+n,[&](vector<ll> x,vector<ll> y){return x[0]>y[0];});
		
		ll s=0,ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				s+=a[i][j];
				ans+=s;
			}
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
