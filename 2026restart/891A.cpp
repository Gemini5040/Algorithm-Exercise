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

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	int countofone=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1){
			countofone++;
		}
	}
	int g=a[0];
	for(int i=1;i<n;i++){
		g=__gcd(g,a[i]);
	}
	if(g!=1){
		cout<<-1<<"\n";
		return;
	}else if(n==1){
		cout<<0<<"\n";
		return;
	}
	int bia=n-1;
	for(int i=0;i<n;i++){
		int tg=a[i];
		for(int j=i+1;j<n;j++){
			tg=__gcd(tg,a[j]);
			if(tg==1){
				bia=min(bia,j-i);
			}
		}
	}
	cout<<n-1+bia-countofone<<"\n";
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
