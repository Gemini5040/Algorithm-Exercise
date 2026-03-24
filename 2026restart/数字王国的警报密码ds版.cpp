#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
using ll=long long;

void solve(){
	int n,k;
	cin>>n>>k;

	if(n>=k){
		cout<<-1<<endl;
	}else{
		set<int> unused;
		for(int i=1;i<k;i++){
			unused.insert(i);
		}

		vector<int> ans;
		int pre=0;
		int la=0;
		for(int i=0;i<n;i++){
			int cur=la+1;
			set<int>::iterator it=unused.lower_bound((pre+cur)%k);
			if(it==unused.end()){
				it=unused.begin();
			}
			int val=*it;
			cur=(cur+(val-(pre+cur)%k+k)%k);
			ans.push_back(cur);
			pre+=cur;
			la=cur;
			unused.erase(it);
		}

		for(int i=0;i<(int)ans.size();i++){
			cout<<ans[i]<<" \n"[i==(int)ans.size()-1];
		}
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
}