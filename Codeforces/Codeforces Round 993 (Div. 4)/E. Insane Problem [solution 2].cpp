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
		int k,l1,r1,l2,r2;
		cin>>k>>l1>>r1>>l2>>r2;
		auto calc=[&](ll r)->ll{
			if(r==0) return 0;
			ll res=0;
			vector<ll> a;
			ll x=l1;
			while(x<=r){
				a.push_back(x);
				x*=k;
			}
			for(ll i=l1;i<=r1;){
				if(a.empty()){
					break;
				}
				ll end=r/(a.back()/i);
				if(end>r1){
					res+=(r1-i+1)*a.size();
					break;
				}
				res+=(end-i+1)*a.size();
				i=end+1;
				x=i;
				a.clear();
				while(x<=r){
					a.push_back(x);
					x*=k;
				}
			}
			return res;
		};
		cout<<calc(r2)-calc(l2-1)<<"\n";
	}
	
	return 0;
}