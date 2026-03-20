#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		
		vector<vector<int>> g(n+10,vector<int>(n+10,0));
		int x=(n+1)>>1,y=(n+1)>>1;
		int num=0;
		g[x][y]=num++;
		int turn=0;
		int step=1;
		int tim=0;
		while(num<n*n){
			for(int i=1;i<=step;i++){
				x+=dx[turn],y+=dy[turn];
				g[x][y]=num++;
			}
			tim++;
			if(tim==2){
				tim=0;
				step++;
			}
			turn=(turn+1)%4;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<g[i][j]<<" \n"[j==n];
			}
		}
	}
	
	return 0;
}

/*
10
1
2
3
4
5
6
7
8
9
10
*/
