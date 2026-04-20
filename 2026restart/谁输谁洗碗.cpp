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

int getval(string s){
	int a=s[0]-'0';
	int b=s[1]-'0';
	int c=s[2]-'0';
	int d=s[3]-'0';
	return a*1000+b*100+c*10+d;
}

int getw(int v){
	if(v==0) return 1;
	int res=0;
	while(v){
		res++;
		v/=10;
	}
	return res;
}

string getstr(int v){
	if(v==0) return "0000";
	int w=getw(v);
	string res="";
	while(v){
		int t=v%10;
		res+=t+'0';
		v/=10;
	}
	for(int i=0;i<4-w;i++){
		res+='0';
	}
	reverse(res.begin(),res.end());
	return res;
}

void solve(){
	int n;
	cin>>n;
	vector<pair<string,int>> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	// sort(a.begin(),a.end(),less<pair<string,int>>());
	// int v1=getval(a[0].first);
	// int v2=getval(a[n-1].first);
	int ans=0;
	for(int v=0;v<=9999;v++){
		string str=getstr(v);
		int flag=0;
		for(int i=0;i<n;i++){
			int cnt=0;
			for(int j=0;j<4;j++){
				if(str[j]==a[i].first[j]){
					cnt++;
				}
			}
			if(cnt!=a[i].second){
				flag=1;
				break;
			}
		}
		if(flag==0){
			ans=v;
			break;
		}
	}
	cout<<getstr(ans)<<endl;
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
