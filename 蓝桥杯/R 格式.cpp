#include <stdio.h>
#include <string.h>

#define N 2000

int mul(int a[],int lenA,int b,int c[]){
	int lenC=0;
	
	for(int i=0,t=0;i<lenA||t;i++){
		if(i<lenA) t+=a[i]*b;
		c[lenC++]=t%10;
		t/=10;
	}
	
	return lenC;
}

int add(int a[],int lenA,int b[],int lenB,int c[]){
	int lenC=lenA>lenB?lenA:lenB;
	
	int t=0;
	for(int i=0;i<lenC;i++){
		if(i<lenA) t+=a[i];
		if(i<lenB) t+=b[i];
		c[i]=t%10;
		t/=10;
	}
	
	if(t){
		c[lenC]=1;
		return lenC+1;
	}
	
	return lenC;
}

int main(){
	int n;
	char str[1050];
	scanf("%d %s",&n,str);
	
	char *dot=strchr(str,'.');
	int lenF=strlen(dot+1);
	char fraction_part[lenF+1];
	strcpy(fraction_part,dot+1);
	
	*dot='\0';
	strcat(str,fraction_part);
	int len=strlen(str);
	
	int Num[N];
	for(int i=0;i<len;i++) Num[i]=str[len-1-i]-'0';
	
	int lenNum=len;
	for(int i=0;i<n;i++){
		int ans[N]={0};
		lenNum=mul(Num,lenNum,2,ans);
		for(int i=0;i<lenNum;i++) Num[i]=ans[i];
	}
	
	int integer[N]={0};
	int pos=0;
	for(int i=lenF;i<=lenNum-1;i++){
		integer[pos++]=Num[i];
	}
	
	int lenInteger=pos;
	if(Num[lenF-1]>=5){
		int ans2[N]={0};
		int one[1]={1};
		lenInteger=add(integer,lenInteger,one,1,ans2);
		for(int i=0;i<lenInteger;i++) integer[i]=ans2[i];
	}
	for(int i=lenInteger-1;i>=0;i--) printf("%d",integer[i]);
	
	return 0;
}