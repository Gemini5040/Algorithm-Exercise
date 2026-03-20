#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF=0x3f3f3f3f3f3f3f3f;
struct info{
	int cs;
	bool st;
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,m;
		cin>>n>>m;
		
		vector<info> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i].cs;
		}
		for(int i=1;i<=m;i++){
			int p;
			cin>>p;
			a[p].st=1;
		}
		sort(a.begin()+1,a.end(),[&](info x,info y){return x.cs<y.cs;});
		
		vector<array<ll,2>> f(n+1,{INF,INF});
		f[1][0]=0;
		if(!a[1].st){
			f[2][0]=0;
		}
		
		auto pw=[&](int x){return 1LL*x*x;};
		
		f[2][1]=pw(a[2].cs-a[1].cs);
		for(int i=3;i<=n;i++){
			f[i][1]=f[i-1][0]+pw(a[i].cs-a[i-1].cs);
			if(!a[i-1].st){
				f[i][0]=min(f[i-1][0],f[i-1][1]);
				f[i][1]=min(f[i][1],f[i-2][0]+pw(a[i].cs-a[i-2].cs));
			}else{
				f[i][0]=f[i-1][1];
			}
		}
		ll ans=f[n][1];
		if(!a[n].st) ans=min(ans,f[n][0]);
		cout<<ans<<"\n";
	}
	
	return 0;
}