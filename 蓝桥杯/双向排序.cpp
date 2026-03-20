#include <bits/stdc++.h>
using namespace std;

int a[100010];

int compare1(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int compare2(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) a[i]=i;
	
	while(m--){
		int op;
		int q;
		cin>>op>>q;
		if(op==0){
			qsort(a+1,q,sizeof(int),compare2);
		}else{
			qsort(a+q,n-q+1,sizeof(int),compare1);
		}
	}
	
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	
	return 0;
}