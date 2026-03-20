#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while((scanf("%d",&n)==1)&&(n!=0)){
		int a[110];
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		
		int sum=0,ans=0;
		for(int i=0;i<n;i++) sum^=a[i];
		if(sum==0) printf("0\n");
		else{
			for(int i=0;i<n;i++){
				if((sum^a[i])<=a[i]){
					ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	
	return 0;
}