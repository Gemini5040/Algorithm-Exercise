#include <bits/stdc++.h>

using namespace std;

const int N=510;

int n,m,k;
int a[N][N];
int s[N][N];

int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		}
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int ii=1;ii<=i;ii++){
				for(int jj=1;jj<=j;jj++){
					int tmp=s[i][j]-s[ii-1][j]-s[i][jj-1]+s[ii-1][jj-1];
					if(tmp<=k) cnt++;
				}
			}
		}
	}
	
	printf("%d",cnt);
	
	return 0;
}