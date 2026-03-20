#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL INF=1e9;
LL n;

LL C(LL a,LL b){
	LL res=1;
	for(LL i=a,j=1;j<=b;i--,j++){
		res=res*i/j;
		if(res>n) return res;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	
	if(n==1){
		cout<<"1"<<endl;
		return 0;
	}
	
	for(int i=16;i>=0;i--){
		LL l=i*2,r=INF;
		while(l<=r){
			LL mid=(l+r)>>1;
			LL lim=C(mid,i);
			if(lim==n){
				cout<<((1+mid)*mid/2+i+1)<<endl;
				return 0;
			}else if(lim<n){
				l=mid+1;
			}else if(lim>n){
				r=mid-1;
			}
		}
	}
	
	return 0;
}