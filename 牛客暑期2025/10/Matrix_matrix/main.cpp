#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll=long long;
using ull=unsigned long long;
using i128=__int128;

const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll P=1e9+7;
const ull H=1e9+7;
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int N=100010;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ull rnd(ull l=0ull,ull r=-1ull){return uniform_int_distribution<ull>(l,r)(rng);}

void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll> step;
	set<ll> ss;
	for(ll i=1;i<=m;i++){
		ll t=i*n%m;
		step.push_back(t);
		ss.insert(t);
	}
	if((ll)ss.size()==m){
		cout<<"YES"<<"\n";
		vector<vector<ll>> g(n,vector<ll>(m,0));
		vector<ll> column(m,0),column_pos(m+1,0);
		column[0]=1;
		column_pos[1]=0;
		ll p=0;
		for(int i=2;i<=m;i++){
			if((i-1)&1){
				column[(p+step[i-2])%m]=i;
				column_pos[i]=p=(p+step[i-2])%m;
			}else{
				column[(p-step[i-2]+n*m)%m]=i;
				column_pos[i]=p=(p-step[i-2]+n*m)%m;
			}
		}
		
//		for(int i=0;i<m;i++){
//			cout<<column[i]<<" \n"[i==m-1];
//		}
		
		ll be=0;
		for(int i=1;i<=m;i++){
			int c=column_pos[i];
			g[be][c]=1;
			p=be;
			for(int j=2;j<=n;j++){
				if((j-1)&1){
					g[(p+j-1)%n][c]=j;
					p=(p+j-1)%n;
				}else{
					g[(p-j+1+n*m)%n][c]=j;
					p=(p-j+1+n*m)%n;
				}
			}
			be=p;
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				ll ans=g[i][j]+(column[j]-1)*n;
				cout<<ans<<" \n"[j==m-1&&i!=n-1];
			}
		}
	}else{
		cout<<"NO";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T=1;
	//cin>>T;
	
	while(T--){
		solve();
	}
	
	return 0;
}

