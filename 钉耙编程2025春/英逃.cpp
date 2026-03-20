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
		int n;
		ll x;
		cin>>n>>x;
		vector<ll> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		vector<ll> f(n+1);
		for(int i=2;i<=n;i++){
			f[i]=f[i-1]+abs(a[i]-a[i-1]);
		}
		if(f[n]<=x){
			cout<<0<<"\n";
			continue;
		}
		auto check=[&](auto len){
			deque<ll> dq;
			auto add=[&](auto x){
				while(dq.size()&&dq.back()<x){
					dq.pop_back();
				}
				dq.push_back(x);
			};
			for(int i=1;i<len;i++){
				add(a[i]);
			}
			for(int i=len;i<=n;i++){
				add(a[i]);
				int j=i-len+1;
				if(dq.front()==a[j-1]){
					dq.pop_front();
				}
				ll sum=0;
				ll ma=dq.front();
				if(j>1){
					sum+=f[j-1];
					sum+=abs(ma-a[j-1]);
				}
				if(i<n){
					sum+=f[n]-f[i+1];
					sum+=abs(a[i+1]-ma);
				}
				if(sum<=x){
					return 1;
				}
			}
			return 0;
		};
		int l=2,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		cout<<l<<"\n";
	}
	
	return 0;
}