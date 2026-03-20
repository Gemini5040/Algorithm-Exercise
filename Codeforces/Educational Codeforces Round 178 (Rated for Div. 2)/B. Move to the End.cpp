#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=200010;
ll a[N];
ll b[N];
ll sum[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		fill(a,a+N,0);
		fill(b,b+N,0);
		fill(sum,sum+N,0);
		
		int n;
		cin>>n;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		
		for(int i=1;i<=n;i++){
			b[i]=max(b[i-1],a[i]);
		}
		
		for(int i=1;i<=n;i++){
			int l=n-i+1,r=n;
			ll ans=max(sum[r]-sum[l-1],sum[r]-sum[l]+b[l-1]);
			cout<<ans<<" ";
		}
		
		cout<<"\n";
	}
	
	return 0;
}
