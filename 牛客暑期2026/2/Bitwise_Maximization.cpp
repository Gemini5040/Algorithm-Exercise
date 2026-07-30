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
const int N=500010;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ull rnd(ull l=0ull,ull r=-1ull){return uniform_int_distribution<ull>(l,r)(rng);}

int n;
bool zero;
ll a[N];

// 你的高斯消元完全没动，和你写的一模一样
void Gauss(){
	int i,k=1;
	ll j=(ll)1<<62;
	for(;j;j>>=1){
		for(i=k;i<=n;i++){
			if(a[i]&j) break;
		}
		if(i>n) continue;
		swap(a[i],a[k]);
		for(i=1;i<=n;i++){
			if(i!=k&&a[i]&j){
				a[i]^=a[k];
			}
		}
		k++;
	}
	k--;
	if(k!=n) zero=true;
	else zero=false;
	n=k;
}

ll Query(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		if((ans ^ a[i]) > ans){
			ans ^= a[i];
		}
	}
	return ans;
}

void solve(){
	cin>>n;
	int y=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		y^=a[i];
	}

	for(int i=1;i<=n;i++){
		a[i] &= (~y);
	}

	Gauss();

	ll x = Query();
	cout<< y + 2 * x <<endl;
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
