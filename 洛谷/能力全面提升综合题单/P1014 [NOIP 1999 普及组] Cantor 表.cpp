#include <bits/stdc++.h>
using namespace std;

int sum[10010];
int fd(int target){
	int l=0,r=10000;
	while(r-l>1){
		int mid=(l+r+1)>>1;
		if(sum[mid]<=target) l=mid;
		else r=mid;
	}
	return l;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for(int i=1;i<=10000;i++){
		sum[i]=i*(i+1)/2;
	}
	
	int n;
	cin>>n;
	
	int line=fd(n);
	int d=n-sum[line];
	int x=0,y=0;
	if(line&1){
		x=1,y=line;
	}else{
		x=line,y=1;
	}
	if(d){
		if(line&1){
			x=d,y=line+1-d+1;
		}else{
			x=line+1-d+1,y=d;
		}
	}
	
	cout<<x<<"/"<<y<<"\n";
	
	return 0;
}
