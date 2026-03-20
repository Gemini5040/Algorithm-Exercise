#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=1000010;
string s[N];
int dx[3]={1,-1,0};
int dy[3]={0,0,1};

void broadcast(vector<vector<int>>& dist,int x,int y,int n,int val){
	if(x<0||x>=n) return;
	if(dist[x][y]==-1) return;
	if(dist[x][y]>=val) return;
	dist[x][y]=val;
	broadcast(dist,x-1,y,n,val);
	broadcast(dist,x+1,y,n,val);
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
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<s[i][j]<<" \n"[j==m-1];
			}
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
		
		int ans=0;
		for(int j=m-1;j>0;j--){
			for(int i=0;i<n;i++){
				if(bad[i][j-1]&&bad[i][j]){
					dist[i][j-1]=dist[i][j]+1;
				}
			}
			vector<pair<int,int>> lst;
			for(int i=0;i<n;i++){
				if(bad[i][j-1]){
					lst.emplace_back(dist[i][j-1],i);
				}
			}
			sort(lst.begin(),lst.end(),greater<pair<int,int>>());
			for(auto [u,v]:lst){
				broadcast(dist,v-1,j-1,n,u);
				broadcast(dist,v+1,j-1,n,u);
			}
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				ans=max(ans,dist[i][j]+1);
			}
		}
		
		cout<<T<<" "<<(k<=ans?"YES":"NO")<<"\n";
	}
	
	return 0;
}
