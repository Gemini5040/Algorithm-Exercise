#include <bits/stdc++.h>
using namespace std;

const int N=15;

int n;
int column[N],diagonalL[N*2],diagonalR[N*2];
int g[3000][N];
int pos=1;

void dfs(int u,int st){
	if(u==n){
//		for(int i=0;i<n;i++){
//			for(int j=1;j<column[i];j++){
//				cout<<"*";
//			}
//			cout<<"Q";
//			for(int j=column[i]+1;j<=n;j++){
//				cout<<"*";
//			}
//			cout<<"\n";
//		}
//		cout<<"\n";

		for(int i=0;i<n;i++){
			g[pos][i]=column[i];
		}
		pos++;
		return;
	}
	
	for(int i=0;i<n;i++){
		if(!(st>>i&1)&&(!diagonalL[u+i+1]&&!diagonalR[n-i+u])){
			column[u]=i+1;
			diagonalL[u+i+1]=1;
			diagonalR[n-i+u]=1;
			dfs(u+1,st|(1<<i));
			diagonalL[u+i+1]=0;
			diagonalR[n-i+u]=0;
		}
	}
	
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	dfs(0,0);
	
	int ans=0;
	int flag=1;
	for(int i=1;i<pos;i++){
		for(int j=i+1;j<pos;j++){
			flag=1;
			for(int k=0;k<n;k++){
				if(g[i][k]==g[j][k]){
					flag=0;
					break;
				}
			}
			if(flag){
				ans++;
			}
		}
	}
	
	cout<<ans*2<<"\n";
	
	return 0;
}