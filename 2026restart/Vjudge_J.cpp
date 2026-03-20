#include <bits/stdc++.h>
using namespace std;

const int N=150010;

vector<int> fa(2*N,0),lc(2*N,0),rc(2*N,0);

int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=2*n;i++){
		fa[i]=i;
	}

	int sz=n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		int rx=find(x);
		int ry=find(y);
		int id=++sz;
		lc[id]=rx;
		rc[id]=ry;
		fa[rx]=fa[ry]=id;
	}

	int cur=sz;
	stack<int> st;
	vector<int> ans;
	while(cur||!st.empty()){
		while(cur){
			st.push(cur);
			cur=lc[cur];
		}
		cur=st.top();
		st.pop();
		if(cur<=n){
			ans.push_back(cur);
		}
		cur=rc[cur];
	}

	for(int i=0;i<n;i++){
		cout<<ans[i]<<" \n"[i==n-1];
	}
}

int main(){
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