#include <bits/stdc++.h>
using namespace std;

const int N=11;
int n,k;
int g[N][N];
bool st[N][N];
bool edge[N][N][N][N];
char path[110];
int path_len;
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

bool dfs(int x1,int y1){
	if(x1==n-1&&y1==n-1&&path_len==n*n-1){
		return true;
	}
	
	st[x1][y1]=true;
	for(int i=0;i<8;i++){
		int x2=x1+dx[i],y2=y1+dy[i];
		if(x2<0||x2>=n||y2<0||y2>=n) continue;
		if((g[x1][y1]+1)%k!=g[x2][y2]) continue;
		if(st[x2][y2]) continue;
		if(i%2&&(edge[x1][y2][x2][y1]||edge[x2][y1][x1][y2])) continue;
		
		edge[x1][y1][x2][y2]=true;
		path[path_len++]=i+'0';
		if(dfs(x2,y2)) return true;
		path_len--;
		edge[x1][y1][x2][y2]=false;
	}
	
	st[x1][y1]=false;
	return false;
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&g[i][j]);
		}
	}
	
	if(dfs(0,0)){
		for(int i=0;i<path_len;i++){
			printf("%c",path[i]);
		}
	}else{
		printf("-1");
	}
	
	return 0;
}