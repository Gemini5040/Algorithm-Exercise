#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=100010;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,k;
		cin>>n>>k;
		
		vector<int> a(n);
		for(auto &x:a){
			cin>>x;
		}
		sort(a.begin(),a.end(),[&](int x,int y){return x<y;});
		
		int l=(n-k+1)>>1,r=n-l+1;
		int ans=a[r-1]-a[l-1]+1;
		cout<<ans<<"\n";
	}
	
	return 0;
}
