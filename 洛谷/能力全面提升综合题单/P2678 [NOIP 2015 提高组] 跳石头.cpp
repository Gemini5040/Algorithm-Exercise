#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=500010;
int a[N];
int d,n,m;

bool check(int x){
	int cnt=0;
	int cur=0;
	for(int i=1;i<=n+1;i++){
		if(a[i]-a[cur]<x) cnt++;
		else cur=i;
	}
	
	return cnt<=m;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>d>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=d;
	
	int l=1,r=d;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	
	cout<<l<<"\n";
	
	return 0;
}
