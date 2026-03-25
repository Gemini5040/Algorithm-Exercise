#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
using ll=long long;

int find(int u,vector<int> &p){
	if(u!=p[u]) return p[u]=find(p[u],p);
	return u;
}

void solve(){
	int n,k;
	cin>>n>>k;

	if(n>=k){
		cout<<-1<<endl;
		return;
	}

	vector<int> p(k);
	for(int i=1;i<k;i++){
		p[i]=i;
	}
	p[0]=1;

	int prev=0;
	int la=0;
	vector<int> ans;
	for(int i=0;i<n;i++){
		int cur=la+1;
		int val=find((prev+cur)%k,p);
		cur+=(val-(prev+cur)%k+k)%k;
		ans.push_back(cur);
		la=cur;
		prev+=cur;
		p[val]=find((val+1)%k,p);
	}

	for(int i=0;i<n;i++){
		cout<<ans[i]<<" \n"[i==n-1];
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