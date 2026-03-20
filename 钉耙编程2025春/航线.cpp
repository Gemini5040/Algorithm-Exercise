#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int N=100000;
const int64 INF=(1LL<<60)-1;
const int dx[4]={0,-1,0,1};
const int dy[4]={1,0,-1,0};

int n,m,t[N+9],d[N+9];

int Encode(int x,int y){
	return (x-1)*m+y;
}

pair<int,int> Decode(int id){
	return make_pair((id-1)/m+1,(id-1)%m+1);
}

void Read(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>t[Encode(i,j)];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>d[Encode(i,j)];
		}
	}
}

int64 dis[N+9][4];
bool vis[N+9][4];

void Dijkstra(){
	int st=Encode(1,1);
	int td=Encode(n,m);
	
	for(int i=1;i<=n*m;i++){
		for(int j=0;j<4;j++){
			dis[i][j]=INF;
			vis[i][j]=false;
		}
	}
	
	priority_queue<
		tuple<int64,int,int>,
		vector<tuple<int64,int,int>>,
		greater<tuple<int64,int,int>>
	> pq;
	
	dis[st][0]=t[st];
	pq.emplace(dis[st][0],st,0);
	
	while(!pq.empty()){
		auto [val,p,u]=pq.top();
		pq.pop();
		if(vis[p][u]) continue;
		vis[p][u]=true;
		
		for(int v=0;v<4;v++){
			if(dis[p][u]+d[p]>=dis[p][v]) continue;
			dis[p][v]=dis[p][u]+d[p];
			pq.emplace(dis[p][v],p,v);
		}
		
		auto [x,y]=Decode(p);
		x+=dx[u];
		y+=dy[u];
		
		auto OutMap=[&](int x,int y){
			return x<1||x>n||y<1||y>m;
		};
		
		if(!OutMap(x,y)){
			int q=Encode(x,y);
			if(dis[p][u]+t[q]<dis[q][u]){
				dis[q][u]=dis[p][u]+t[q];
				pq.emplace(dis[q][u],q,u);
			}
		}
	}
	
	cout<<dis[td][3]<<'\n';
}

void work(){
	Read();
	Dijkstra();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	while(T--) work();
	
	return 0;
}