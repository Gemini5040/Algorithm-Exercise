#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		
		vector<ll> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a.begin(),a.end(),[&](ll x,ll y){return x<y;});
		
		ll g=0;
		for(int i=1;i<n;i++){
			if(a[i]%a[0]==0){
				g=gcd(g,a[i]);
			}
		}
		cout<<(g==a[0]?"YES":"NO")<<"\n";
	}
	
	return 0;
}
