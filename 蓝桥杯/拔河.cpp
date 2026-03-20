#include <bits/stdc++.h>
using namespace std;

const int N=1010;
int n;
long long a[N];
multiset<long long> s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			s.insert(a[r]-a[l-1]);
		}
	}
	
	long long ans=0x3f3f3f3f;
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			s.erase(s.find(a[j]-a[i-1]));
		}
		
		for(int j=1;j<=i;j++){
			auto target=a[i]-a[j-1];
			auto pos=s.lower_bound(target);
			if(pos!=s.end()){
				ans=min(ans,abs(*pos-target));
			}
			if(pos!=s.begin()){
				pos--;
				ans=min(ans,abs(*pos-target));
			}
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}