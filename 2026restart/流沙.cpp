#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
using ll=long long;

const int INF=0x3f3f3f3f3f3f3f3f;

struct node{
	int val=0;
	vector<int> ne;
	int sum=0,cnt=0;
	int f=0;
};

pair<int,int> dfs1(vector<node> &tree,int fa,int cur){
	tree[cur].sum+=tree[cur].val;
	tree[cur].cnt+=1;
	for(int i=0;i<(int)tree[cur].ne.size();i++){
		if(tree[cur].ne[i]==fa){
			continue;
		}
		pair<int,int> pp=dfs1(tree,cur,tree[cur].ne[i]);
		tree[cur].sum+=pp.first;
		tree[cur].cnt+=pp.second;
	}
	return make_pair(tree[cur].sum,tree[cur].cnt);
}

void dfs2(vector<node> &tree,int fa,int cur){
	for(int i=0;i<(int)tree[cur].ne.size();i++){
		if(tree[cur].ne[i]==fa){
			continue;
		}
		dfs2(tree,cur,tree[cur].ne[i]);
	}
	int mnf=INF;
	for(int i=0;i<(int)tree[cur].ne.size();i++){
		if(tree[cur].ne[i]==fa){
			continue;
		}
		mnf=min(mnf,tree[tree[cur].ne[i]].f);
	}

	tree[cur].f=min(mnf,tree[cur].sum/tree[cur].cnt);
}

void solve(){
	int n;
	cin>>n;
	vector<node> tree(n+1);

	for(int i=1;i<=n;i++){
		cin>>tree[i].val;
	}

	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		tree[u].ne.push_back(v);
		tree[v].ne.push_back(u);
	}

	dfs1(tree,0,1);
	dfs2(tree,0,1);

	for(int i=1;i<=n;i++){
		cout<<tree[i].f<<" \n"[i==n];
	}
}

signed main(){
	int size(256<<20);  // 256M
	asm ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T=1;
	cin>>T;

	while(T--){
		solve();
	}

	exit(0);
}