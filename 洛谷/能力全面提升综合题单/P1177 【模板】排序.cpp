#include <bits/stdc++.h>
using namespace std;

const int N=100010;
int a[N];

void quick_sort(int l,int r){
	if(l>=r) return;
	
	int i=l-1,j=r+1,mid=a[(l+r)>>1];
	while(i<j){
		do i++; while(a[i]<mid);
		do j--; while(a[j]>mid);
		if(i<j) swap(a[i],a[j]);
	}
	
	quick_sort(l,j);
	quick_sort(j+1,r);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	quick_sort(1,n);
	
	for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
	
	return 0;
}
