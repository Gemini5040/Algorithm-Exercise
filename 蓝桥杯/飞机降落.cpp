#include <bits/stdc++.h>
using namespace std;

typedef struct Plane{
	int T,D,L;
}Plane;

Plane planes[10];
bool st[10];
int n;

bool dfs(int cnt,int last_end){
	if(cnt==n) return true;
	
	for(int i=0;i<n;i++){
		if(!st[i]){
			int T=planes[i].T;
			int D=planes[i].D;
			int L=planes[i].L;
			int earliest_start=max(last_end,T);
			int lastest_start=T+D;
			if(earliest_start>lastest_start) continue;
			int new_end=earliest_start+L;
			st[i]=true;
			if(dfs(cnt+1,new_end)) return true;
			st[i]=false;
		}
	}
	
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			int t,d,l;
			cin>>t>>d>>l;
			planes[i]=(Plane){t,d,l};
		}
		memset(st,0,sizeof(st));
		bool res=dfs(0,0);
		cout<<(res?"YES":"NO")<<endl;
	}
	
	return 0;
}