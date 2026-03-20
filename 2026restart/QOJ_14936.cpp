#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"
using ll=long long;

void solve(){
	auto rev=[&](int n)->int{
		vector<int> a(8);
		for(int i=0;i<8;i++){
			a[i]=n&1;
			n>>=1;
		}
		int ans=0;
		for(int i=0;i<8;i++){
			ans=ans*2+a[i];
		}
		return ans;
	};

	auto out=[&](int n)->void{
		n=rev(n);
		for(int i=0;i<8;i++){
			cout<<(n&1);
			n>>=1;
		}
		cout<<endl;
	};

	map<int,int> mp1,mp2;
	int idx=0;
	for(int i=1923;i<=2024;i++){
		while(mp2.count(idx)||mp2.count(rev(idx))) idx++;
		mp1[i]=idx;
		mp2[idx]=i;
		mp2[rev(idx)]=i;
	}

	string op;
	cin>>op;

	if(op=="write"){
		int y;
		cin>>y;
		out(mp1[y]);
	}else{
		string s;
		cin>>s;
		int n=0;
		for(auto ss:s){
			n=n*2+ss-'0';
		}
		cout<<mp2[n]<<endl;
	}
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