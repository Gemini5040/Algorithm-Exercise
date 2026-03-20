#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,-1,0};

bool check(vector<vector<int>> &p,int lim,int n,int m){
	queue<pair<int,int>> q;
	vector<vector<bool>> st(n+10,vector<bool>(m+10,false));
	for(int j=1;j<=m;j++){
		q.emplace(1,j);
		st[1][j]=true;
	}
	while(!q.empty()){
		pair<int,int> t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int x=t.first+dx[i],y=t.second+dy[i];
			if(x>=1&&x<=n&&y>=1&&y<=m&&st[x][y]==0&&p[x][y]<=lim){
				if(x==n) return true;
				q.emplace(x,y);
				st[x][y]=true;
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,m;
		cin>>n>>m;
		
		vector<vector<int>> p(n+10,vector<int>(m+10));
		int mi=INT_MAX,ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>p[i][j];
				if(i>1&&i<n) mi=min(mi,p[i][j]);
				ma=max(ma,p[i][j]);
			}
		}
		
		int l=mi,r=ma;
		while(l<r){
			int mid=(l+r)>>1;
			if(!check(p,mid,n,m)) l=mid+1;
			else r=mid;
		}
		
		cout<<l<<"\n";
	}
	
	return 0;
}
