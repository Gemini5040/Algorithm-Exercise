#include <bits/stdc++.h>

int main(){
	int T;
	scanf("%d",&T);
	
	while(T--){
		int n;
		scanf("%d",&n);
		if(n%6==0) printf("Roy wins!\n");
		else printf("October wins!\n");
	}
	
	return 0;
}