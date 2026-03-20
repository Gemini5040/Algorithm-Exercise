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

int cal(vector<int> &a,vector<int> &b,int mid){
	auto pos1=lower_bound(a.begin()+1,a.end(),mid);
	int num=a.end()-pos1;
	auto pos2=upper_bound(b.begin()+1,b.end(),num);
	pos2--;
	int cnt=pos2-b.begin();
	return cnt*mid;
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1,0),b(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		b[i]=b[i-1]+t;
	}
	sort(a.begin()+1,a.end());
	int ans=0;
	set<int> ss;
	for(int i=1;i<=n;i++){
		ss.insert(a[i]);
	}
	for(auto m:ss){
		ans=max(ans,cal(a,b,m));
	}
	cout<<ans<<endl;
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
