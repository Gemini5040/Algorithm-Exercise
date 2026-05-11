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

void solve(){
	int n,a,b;
	cin>>n>>a>>b;

	int s;
	cin>>s;

	vector<int> fs(20,0),ts(20,0);
	vector<int> ispd(20,0);
	vector<int> haveac(20,0);

	int ac1=0;

	int num=0,sumt=0;

	for(int i=0;i<s;i++){
		int t;
		string p,v;
		cin>>t>>p>>v;

		int pp=p[0]-'A';
		if(haveac[pp]==1){
			continue;
		}
		if(v=="ac"){
			haveac[pp]=1;
			ac1++;
			num++;
			fs[pp]=t+ts[pp]*20;
			sumt+=fs[pp];
		}else if(v=="rj"){
			ts[pp]++;
		}else if(v=="pd"){
			haveac[pp]=1;
			fs[pp]=t+ts[pp]*20;
			ispd[pp]=fs[pp];
		}
	}

	sort(ispd.begin(),ispd.end());

	int st=-1;
	for(int i=0;i<20;i++){
		if(ispd[i]){
			st=i;
			break;
		}
	}

	if(st!=-1){
		for(int i=st;i<20;i++){
			if((num==a&&sumt<b)||(num>a)){
				break;
			}
			num++;
			sumt+=ispd[i];
		}
	}

	if(!((num==a&&sumt<b)||(num>a))){
		cout<<-1<<endl;
		return;
	}
	if(ac1>a){
		cout<<0<<endl;
		return;
	}
	cout<<num-ac1<<endl;
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
