#include <bits/stdc++.h>

using namespace std;

const int N=100010;
const int MOD=1000000007;

int n,ma,mb;
int numA[N],numB[N];

int main(){
	scanf("%d",&n);
	scanf("%d",&ma);
	for(int i=ma-1;i>=0;i--) scanf("%d",&numA[i]);
	scanf("%d",&mb);
	for(int i=mb-1;i>=0;i--) scanf("%d",&numB[i]);
	
	long long res=0,base=1;
	for(int i=0;i<ma;i++){
		int weight=max(max(numA[i],numB[i])+1,2)%MOD;
		res=(res+(numA[i]-numB[i])*base)%MOD;
		base=(base*weight)%MOD;
	}
	
	printf("%d",res%MOD);
	
	return 0;
}