#include <iostream>

using namespace std;

int power10(int x){
	int res=1;
	for(int i=1;i<=x;i++) res*=10;
	return res;
}

int get(int num[],int l,int r){
	int res=0;
	for(int i=l;i>=r;i--){
		res=res*10+num[i];
	}
	return res;
}

int count(int n,int x){
	if(n==0) return 0;
	
	int num[10],size=0;
	while(n){
		num[size++]=n%10;
		n/=10;
	}
	
	int res=0;
	for(int i=size-1-(x==0);i>=0;i--){
		res+=get(num,size-1,i+1)*power10(i);
		if(x==0) res-=power10(i);
		
		if(num[i]==x) res+=get(num,i-1,0)+1;
		else if(num[i]>x) res+=power10(i);
	}
	
	return res;
}

int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	
	printf("%d",count(n,x));
	
	return 0;
}