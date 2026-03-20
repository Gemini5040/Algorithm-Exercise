#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int upper_bound(int *x,int n,int target){
	int left=0,right=n;
	while(left<right){
		int mid=(left+right)/2;
		if(x[mid]<=target) left=mid+1;
		else right=mid;
	}
	return left;
}

int main(){
	int t;
	scanf("%d",&t);
	
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		
		int *x=(int*)malloc(n*sizeof(int));
		for(int i=0;i<n;i++) scanf("%d",&x[i]);
		qsort(x,n,sizeof(int),compare);
		
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
		}
		
		int *cnt=(int*)malloc(n*sizeof(int));
		for(int i=0;i<n;i++){
			int target=x[i]+k;
			int pos=upper_bound(x,n,target);
			cnt[i]=pos-i;
		}
		
		int *max_right=(int*)malloc((n+1)*sizeof(int));
		max_right[n]=0;
		for(int i=n-1;i>=0;i--){
			max_right[i]=cnt[i]>max_right[i+1]?cnt[i]:max_right[i+1];
		}
		
		int max_two=0;
		for(int i=0;i<n;i++){
			int next_start=cnt[i]+i;
			int other=(next_start<n)?max_right[next_start]:0;
			max_two=max_two>(cnt[i]+other)?max_two:(cnt[i]+other);
		}
		
		printf("%d\n",max_two);
		
		free(x);
		free(cnt);
		free(max_right);
	}
	
	return 0;
}