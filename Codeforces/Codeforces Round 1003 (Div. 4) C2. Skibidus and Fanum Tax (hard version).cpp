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
		int n,m;
		cin>>n>>m;
		
		vector<ll> a(n),b(m);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<m;i++){
			cin>>b[i];
		}
		sort(b.begin(),b.end(),less<ll>());
		
		bool flag=true;
		ll last=0;
		for(int i=0;i<n;i++){
			if(i==0){
				last=min(a[0],b[0]-a[0]);
			}else{
				ll target=last+a[i];
				auto it=lower_bound(b.begin(),b.end(),target);
				if(it==b.end()){
					if(a[i]<last){
						flag=false;
						break;
					}else{
						last=a[i];
					}
				}else{
					if(a[i]>=last) last=min(a[i],(*it)-a[i]);
					else last=(*it)-a[i];
				}
			}
		}
		
		cout<<(flag?"YES":"NO")<<"\n";
	}
	
	return 0;
}
