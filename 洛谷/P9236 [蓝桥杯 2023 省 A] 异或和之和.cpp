#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=100010;
ll n;
ll a[N],w[20][2];
ll ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i-1]^a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<20;j++){
			w[j][a[i]>>j&1]++;
		}
	}
	for(int i=0;i<20;i++){
		ans+=w[i][0]*w[i][1]*(1<<i);
	}
	
	cout<<ans<<"\n";
	
	return 0;
}