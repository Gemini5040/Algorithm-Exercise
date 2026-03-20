#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	
	
	int res=0;
	for(int i=1;i<=n;i++){
		int t=1;
		int j=i;
		int flag=1;
		while(j){
			if(t){
				if((j&1)==0){
					flag=0;
					break;
				}
			}else{
				if((j&1)==1){
					flag=0;
					break;
				}
			}
			j/=10;
			t=1-t;
		}
		if(flag) res++;
	}
	
	printf("%d",res);
	
	return 0;
}