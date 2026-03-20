#include <bits/stdc++.h>

using namespace std;

const int N=110;

int n,m;
int g[N][N];
int c[N][N];

int main(){
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&g[i][j]);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]){
				c[i-1][j-1]++;
				c[i-1][j]++;
				c[i-1][j+1]++;
				c[i][j-1]++;
				c[i][j+1]++;
				c[i+1][j-1]++;
				c[i+1][j]++;
				c[i+1][j+1]++;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]){
				printf("9 ");
				continue;
			}
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}