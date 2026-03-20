#include <bits/stdc++.h>
using namespace std;

const int MOD=1000000007;
const int N=10000010;

long long d[N][3];
int n;

int main(){
	scanf("%d",&n);
	
	d[0][1]=1;
	d[1][1]=1;
	for(int i=2;i<=n;i++){
		d[i][0]=(d[i-2][1]+d[i-1][2])%MOD;
		d[i][1]=(d[i-1][1]+d[i-1][2]+d[i-1][0]+d[i-2][1])%MOD;
		d[i][2]=(d[i-2][1]+d[i-1][0])%MOD;
	}
	
	printf("%lld",d[n][1]%MOD);
	
	return 0;
}