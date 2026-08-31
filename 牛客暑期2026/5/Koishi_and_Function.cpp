#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define endl "\n"
#define int long long

const int M=998244353;

const int N=1e7+5;
int g[N];
int f[N];
int prime[N];
bool vis[N];
int cnt=0;
void euler_sieve(){
	memset(f,0,sizeof(f));
	int n=N-1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[cnt++]=i;
			f[i]=1;
		}
		for(int j=0;j<cnt;j++){
			if(i*prime[j]>n) break;
			vis[i*prime[j]]=1;
			f[i*prime[j]]=f[i]+f[prime[j]];
			if(i%prime[j]==0) break;
		}
	}
}

void func(){
	g[1]=1;
	for(int i=2;i<N;i++){
		if(f[i]==1) g[i]=1;
		else g[i]=prime[f[i]-2];
	}
}

void solve(){
	int n,c;
	cin>>n>>c;
	int ans=0;
	int tc=c;
	for(int i=1;i<=n;i++){
		ans=(ans+g[i]*tc)%M;
		tc=(tc*c)%M;
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	euler_sieve();
	func();

	int T=1;
	// cin>>T;

	while(T--){
		solve();
	}

	return 0;
}