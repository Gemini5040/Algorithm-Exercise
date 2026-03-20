#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	
	int max=0x3f3f3f3f;
	int min;
	int arrA[N],posA=0;
	int arrB[N],posB=0;
	
	while(N--){
		int a,b;
		scanf("%d %d",&a,&b);
		arrA[posA++]=a;
		arrB[posB++]=b;
		
		int t=a/b;
		if(max>t) max=t;
	}
	
	int flag=0;
	for(int i=max;i>=1;i--){
		for(int j=0;j<posA;j++){
			if(arrA[j]-arrB[j]*i>=i){
				flag=1;
				//printf("11111\n",min);
				break;
			}
		}
		if(flag){
			min=i+1;
			//printf("%d\n",min);
			break;
		}
	}
	
	printf("%d %d",min,max);
	
	return 0;
}