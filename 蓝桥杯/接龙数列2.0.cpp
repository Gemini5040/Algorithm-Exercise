#include <bits/stdc++.h>

using namespace std;

const int N=100010;

int n;
int a[N];
int last[10];
int max_len;

int getHead(int x){
	if(x==0) return 0;
	int tmp=x;
	int maxDigit=0;
	while(tmp){
		maxDigit++;
		tmp/=10;
	}
	return x/pow(10,maxDigit-1);
}

int getTail(int x){
	return x%10;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	for(int i=0;i<n;i++){
		int h=getHead(a[i]);
		int t=getTail(a[i]);
		
		int current=last[h]+1;
		last[t]=max(last[t],current);
		max_len=max(max_len,current);
	}
	
	printf("%d",n-max_len);
	
	return 0;
}