#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=1000010;
string s[N];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int flag=0;
void dfs(vector<vector<int>>& bad,int n,int m,int k,int sy,int x,int y){
	if(y-sy+1>=k) flag=1;
	bad[x][y]=0;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0||nx>=n||ny<0||ny>=m||bad[nx][ny]==0) continue;
		dfs(bad,n,m,k,sy,nx,ny);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		
		vector<vector<int>> vis(n,vector<int>(m,0));
		vector<vector<int>> vis2(n,vector<int>(m,0));
		vector<vector<int>> bad(n,vector<int>(m,0));
		vector<vector<int>> dist(n,vector<int>(m,0));
		
		vis[0][0]=1;
		queue<pair<int,int>> q;
		q.emplace(0,0);
		while(!q.empty()){
			auto [u,v]=q.front();
			q.pop();
			for(int i=0;i<3;i++){
				int nu=u+dx[i],nv=v+dy[i];
				if(nu>=0&&nu<n&&nv>=0&&nv<m&&s[nu][nv]=='0'&&!vis[nu][nv]){
					vis[nu][nv]=1;
					q.emplace(nu,nv);
				}
			}
		}
		
		vis2[0][m-1]=1;
		q.emplace(0,m-1);
		while(!q.empty()){
			auto [u,v]=q.front();
			q.pop();
			for(int i=0;i<3;i++){
				int nu=u+dx[i],nv=v-dy[i];
				if(nu>=0&&nu<n&&nv>=0&&nv<m&&s[nu][nv]=='0'&&!vis2[nu][nv]){
					vis2[nu][nv]=1;
					q.emplace(nu,nv);
				}
			}
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(vis[i][j]&&!vis2[i][j]){
					bad[i][j]=1;
				}else{
					bad[i][j]=0;
					dist[i][j]=-1;
				}
			}
		}
		
		flag=0;
		for(int j=0;j<m;j++){
			for(int i=0;i<n;i++){
				if(bad[i][j]){
					dfs(bad,n,m,k,j,i,j);
				}
			}
		}
		
		cout<<(flag?"YES":"NO")<<"\n";
	}
	
	return 0;
}
