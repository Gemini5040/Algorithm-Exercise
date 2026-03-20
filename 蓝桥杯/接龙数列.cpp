#include <bits/stdc++.h>

using namespace std;

#define N 100010

int n;
int a[N];
int f[N];

int power10(int x){
	int res=1;
	for(int i=1;i<=x;i++) res*=10;
	return res;
}

int getMaxDigit(int x){
	int res=0;
	if(x==0) res=1;
	while(x){
		x/=10;
		res++;
	}
	return res;
}

int getH(int x){
	int maxDigit=getMaxDigit(x);
	return x/(power10(maxDigit-1));
}

int getT(int x){
	return x%10;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++){
		f[i]=1;
		int i_head=getH(a[i]);
		for(int j=1;j<i;j++){
			if(getT(a[j])==i_head) f[i]=max(f[i],f[j]+1);
		}
	}
	
	int res=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(f[i]>res) res=f[i];
	}
	
	printf("%d",n-res);
	
	return 0;
}