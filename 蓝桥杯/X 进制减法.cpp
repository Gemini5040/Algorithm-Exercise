#include <bits/stdc++.h>

using namespace std;

#define N 1000000007

int n,ma,mb;
int arrM[100000],pos=0;

int f(int x){
	int res=1;
	for(int i=x+1;i<=pos-1;i++) res*=arrM[i];
	return res;
}

int main(){
	scanf("%d",&n);
	
	scanf("%d",&ma);
	int arr[ma];
	for(int i=0;i<ma;i++){
		scanf("%d",&arr[i]);
		if(arr[i]==0) arrM[i]=2;
		else arrM[i]=arr[i]+1;
	}
	
	
	scanf("%d",&mb);
	for(int i=0;i<mb;i++){
		int tmp;
		scanf("%d",&tmp);
		arrM[pos++]=max(arrM[i],tmp+1);
		arr[i]-=tmp;
	}
	
	arrM[pos-1]=2;
	
	int res=0;
	for(int i=ma-1;i>=0;i--){
		res+=arr[i]*f(i);
	}
	
	printf("%d",res);
	
	return 0;
}