#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
using ll=long long;

string s;

bool check(int i){
	if(i<0) return false;
	if(i+3>=s.size()) return false;
	return s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0';
}

void solve(){
	int q;
	cin>>s>>q;
	int cnt=0;
	for(int i=0;i<(int)s.size();i++){
		if(check(i)) cnt++;
	}
	while(q--){
		int i;
		char v;
		cin>>i>>v;
		i--;
		if(s[i]!=v){
			int before=check(i-3)||check(i-2)||check(i-1)||check(i);
			s[i]=v;
			int after=check(i-3)||check(i-2)||check(i-1)||check(i);
			cnt+=after-before;
		}
		cout<<(cnt?"YES":"NO")<<endl;
	}
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