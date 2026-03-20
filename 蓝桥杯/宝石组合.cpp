#include <bits/stdc++.h>

#define N 500010

int gem[N],num[N];

int main(){
	int n;
	scanf("%d",&n);
	
	int max=-0x3f3f3f3f;
	for(int i=0;i<n;i++){
		scanf("%d",&gem[i]);
		num[gem[i]]++;
		if(gem[i]>max) max=gem[i];
	}
	
	for(int i=max;i>=1;i--){
		int tmp[3],pos=0;
		int cnt=0;
		for(int j=i;j<=max;j+=i){
			if(num[j]){
				cnt+=num[j];
				for(int k=0;k<num[j]&&pos<3;k++){
					tmp[pos++]=j;
				}
			}
			if(cnt==3) break;
		}
		if(cnt==3){
			for(int j=0;j<3;j++){
				printf("%d ",tmp[j]);
			}
			break;
		}
	}
	
	return 0;
}