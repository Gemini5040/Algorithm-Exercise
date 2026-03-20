#include <bits/stdc++.h>
using namespace std;

const int N=100010;
int t[N];

void merge_sort(int a[],int l,int r){
	if(l>=r) return;
	
	int mid=(l+r)>>1;
	merge_sort(a,l,mid);
	merge_sort(a,mid+1,r);
	
	int i=l,j=mid+1,k=0;
	while(i<=mid&&j<=r){
		if(a[i]<a[j]) t[k++]=a[i++];
		else t[k++]=a[j++];
	}
	while(i<=mid) t[k++]=a[i++];
	while(j<=r) t[k++]=a[j++];
	
	for(int i=l,j=0;i<=r;i++,j++) a[i]=t[j];
}

int unique(int a[],int len){
	int *res=a+1;
	for(int *p=a+1;p<a+len;p++){
		if(*p!=*(p-1)){
			*res=*p;
			res++;
		}
	}
	return res-a;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int a[N];
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	merge_sort(a,0,n-1);
	int len=unique(a,n);
	
	cout<<len<<"\n";
	for(int i=0;i<len;i++) cout<<a[i]<<" \n"[i==n-1];
	
	return 0;
}
