#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f;
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m;

bool check(vector<vector<int>>& dis,int mid){
	int l1=-inf,r1=inf,l2=-inf,r2=inf;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(dis[i][j]>mid){
				l1=max(l1,i+j-mid);
				r1=min(r1,i+j+mid);
				l2=max(l2,i-j-mid);
				r2=min(r2,i-j+mid);
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i+j>=l1&&i+j<=r1&&i-j>=l2&&i-j<=r2){
				return false;
			}
		}
	}

	return true;
}

void solve(){
	cin>>n>>m;

	vector<vector<int>> g(n,vector<int>(m));
	vector<vector<int>> dis(n,vector<int>(m,inf));
	queue<pair<int,int>> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
			if(g[i][j]){
				dis[i][j]=0;
				q.emplace(i,j);
			}
		}
	}

	while(!q.empty()){
		auto [x,y]=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=x+dir[i][0],ny=y+dir[i][1];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&dis[nx][ny]>dis[x][y]+1){
				dis[nx][ny]=dis[x][y]+1;
				q.emplace(nx,ny);
			}
		}
	}

	int l=0,r=n+m-2;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(dis,mid)) l=mid+1;
		else r=mid;
	}

	cout<<l<<"\n";
}

int main(){
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