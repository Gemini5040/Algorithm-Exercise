#include <bits/stdc++.h>
using namespace std;

const int N=50;
int g[N][N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	
	int x=1,y=(n+1)>>1;
	int num=1;
	for(int i=1;i<=n*n;i++){
		if(i==1) g[x][y]=num++;
		else if(x==1&&y<n){
			x=n,y=y+1;
			g[x][y]=num++;
		}else if(x>1&&y==n){
			x=x-1,y=1;
			g[x][y]=num++;
		}else if(x==1&&y==n){
			x=x+1,y=y;
			g[x][y]=num++;
		}else if(x>1&&y<n){
			if(!g[x-1][y+1]){
				x=x-1,y=y+1;
				g[x][y]=num++;
			}else{
				x=x+1,y=y;
				g[x][y]=num++;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<g[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
