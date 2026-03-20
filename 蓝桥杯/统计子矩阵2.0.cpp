#include <bits/stdc++.h>
using namespace std;

const int N=510;

int n,m,k;
int a[N][N];
int col_sum[N][N];

int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			col_sum[i][j]=col_sum[i-1][j]+a[i][j];
		}
	}
	
	long long cnt=0;
	int sum_col[N];
	
	for(int x1=1;x1<=n;x1++){
		for(int x2=x1;x2<=n;x2++){
			int col_total=0;
			for(int j=1;j<=m;j++){
				sum_col[j]=col_sum[x2][j]-col_sum[x1-1][j];
				col_total+=sum_col[j];
			}
			
			if(col_total<=k){
				cnt+=m*(m+1)/2;
				continue;
			}
			
			int l=1;
			long long current_sum=0;
			for(int r=1;r<=m;r++){
				current_sum+=sum_col[r];
				while(current_sum>k){
					current_sum-=sum_col[l];
					l++;
				}
				cnt+=r-l+1;
			}
		}
	}
	
	printf("%lld",cnt);
	
	return 0;
}