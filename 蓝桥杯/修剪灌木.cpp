#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	
	int ans[10000];
	int pos=0;
	
	if(n==1){
		ans[0]=1;
		pos=1;
	}else if(n==2){
		ans[0]=2;
		ans[1]=2;
		pos=2;
	}else if(n>=3){
		int tmp=n;
		for(int i=1;i<=n/2;i++){
			int d=n-i;
			ans[pos++]=2*d;
		}
		for(int i=n/2+1;i<=n;i++){
			int d=i-1;
			ans[pos++]=2*d;
		}
	}
	
	for(int i=0;i<pos;i++) printf("%d\n",ans[i]);
	
	return 0;
}