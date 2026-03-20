#include <bits/stdc++.h>
using namespace std;

using ll=long long;

void solve(){
	int n,q;
	cin>>n>>q;
	vector<ll> arr(n+1);
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	vector<ll> lastTime(n+1,0);
	ll globalTime=-1;
	ll globalValue=0;
	for(int p=1;p<=q;p++){
		ll t,i,x;
		cin>>t;
		if(t==1){
			cin>>i>>x;
			ll cur=(lastTime[i]>globalTime)?arr[i]:globalValue;
			sum=sum-cur+x;
			arr[i]=x;
			lastTime[i]=p;
		}else{
			cin>>x;
			sum=n*x;
			globalTime=p;
			globalValue=x;
		}
		cout<<sum<<"\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T=1;
	// cin>>T;

	while(T--){
		solve();
	}

	return 0;
}