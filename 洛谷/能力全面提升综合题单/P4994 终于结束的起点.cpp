#include <bits/stdc++.h>
using namespace std;

const int N=0xAC666;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int m;
	cin>>m;
	
	int l0=0,l1=1;
	int ans=0;
	for(int i=2;;i++){  //循环次数可能会很大
		int l2=(l0+l1)%m;
		if(l1==0&&l2==1){
			ans=i-1;
			break;
		}
		l0=l1,l1=l2;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
