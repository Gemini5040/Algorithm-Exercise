#include <bits/stdc++.h>
using namespace std;

#define int long long
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

struct miner{
	int w,v;
};

int check(vector<miner> &a,vector<pair<int,int>> &q,int mid){
	vector<int> sum1(a.size(),0),sum2(a.size(),0);
	for(int i=1;i<a.size();i++){
		sum1[i]=sum1[i-1]+(a[i].w>=mid);
		sum2[i]=sum2[i-1]+((a[i].w>=mid)*a[i].v);
	}
	int tmp=0;
	for(auto qq:q){
		tmp+=(sum1[qq.second]-sum1[qq.first-1])*(sum2[qq.second]-sum2[qq.first-1]);
	}
	return tmp;
}

void solve(){
	int n,m,s;
	cin>>n>>m>>s;
	vector<miner> a(n+1,{0,0});
	for(int i=1;i<=n;i++){
		cin>>a[i].w>>a[i].v;
	}
	vector<pair<int,int>> q;
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		q.push_back(make_pair(l,r));
	}
	int l1=0,r1=1e18;
	while(l1<r1){
		int mid=(l1+r1+1)>>1;
		if(check(a,q,mid)>=s) l1=mid;
		else r1=mid-1;
	}
	int l2=0,r2=1e18;
	while(l2<r2){
		int mid=(l2+r2)>>1;
		if(check(a,q,mid)<=s) r2=mid;
		else l2=mid+1;
	}
	cout<<min(check(a,q,l1)-s,s-check(a,q,l2))<<endl;
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
