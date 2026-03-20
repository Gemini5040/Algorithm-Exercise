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

void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1,0),b(n+1,0),s(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=n;i>=1;i--){
		if(b[i]>a[i]){
			a[i]=b[i];
		}
	}
	for(int i=n-1;i>=1;i--){
		if(a[i]<a[i+1]){
			a[i]=a[i+1];
		}
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<s[r]-s[l-1]<<" ";
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
