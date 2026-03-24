#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl "\n"
using ll=long long;
using ull=unsigned long long;
using i128=__int128;

const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll inv2=(MOD+1)/2;
const ll P=1e9+7;
const ull H=1e9+7;
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int N=100010;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ull rnd(ull l=0ull,ull r=-1ull){return uniform_int_distribution<ull>(l,r)(rng);}

int find_root(int i,vector<int> &parent){
	if(parent[i]!=i) return parent[i]=find_root(parent[i],parent);
	return i;
}

void solve(){
	int n,k;
	cin>>n>>k;

	if(n>=k){
		cout<<-1<<endl;
		return;
	}

	vector<int> parent(k);
	for(int i=0;i<k;i++){
		parent[i]=i;
	}

	parent[0]=find_root(1%k,parent);

	ll S_mod=0;
	ll a_prev=0;

	for(int i=1;i<=n;i++){
		ll m=a_prev+1;
		int R_target=(S_mod+(m%k))%k;
		int R_actual=find_root(R_target,parent);
		int diff=(R_actual-R_target+k)%k;
		ll a_i=m+diff;
		cout<<a_i<<(i==n?"":" ");
		S_mod=R_actual;
		a_prev=a_i;
		if(i<n){
			parent[R_actual]=find_root((R_actual+1)%k,parent);
		}
	}
	cout<<endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T=1;
	cin>>T;
	
	while(T--){
		solve();
	}
	
	return 0;
}
