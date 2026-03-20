#include <bits/stdc++.h>
using namespace std;

//#define int long long
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

string s;
ll sa,sb,sc;
ll na,nb,nc;
ll pa,pb,pc;
ll r;

bool check(ll mid){
	ll cnta=max(0ll,sa*mid-na);
	ll cntb=max(0ll,sb*mid-nb);
	ll cntc=max(0ll,sc*mid-nc);
	return r-cnta*pa-cntb*pb-cntc*pc>=0;
}

void solve(){
	cin>>s;
	sa=0,sb=0,sc=0;
	for(char ss:s){
		if(ss=='B') sa++;
		else if(ss=='S') sb++;
		else if(ss=='C') sc++;
	}
	cin>>na>>nb>>nc;
	cin>>pa>>pb>>pc;
	cin>>r;
	ll L=0,R=1e13;
	while(L<R){
		ll mid=(L+R+1)>>1;
		if(check(mid)) L=mid;
		else R=mid-1;
	}
	cout<<L<<endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T=1;
	// cin>>T;
	
	while(T--){
		solve();
	}
	
	return 0;
}
