#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=200010;
vector<ll> L(N),R(N),C;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		L.clear();
		R.clear();
		C.clear();
		
		int n,k;
		cin>>n>>k;
		
		for(int i=0;i<n;i++) cin>>L[i];
		for(int i=0;i<n;i++) cin>>R[i];
		
		ll ans=1LL;
		for(int i=0;i<n;i++){
			if(L[i]>R[i]){
				ans+=L[i];
				C.push_back(R[i]);
			}else{
				ans+=R[i];
				C.push_back(L[i]);
			}
		}
		sort(C.begin(),C.end(),[&](ll x,ll y){return x>y;});
		
		for(int i=0;i<k-1;i++){
			ans+=C[i];
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
