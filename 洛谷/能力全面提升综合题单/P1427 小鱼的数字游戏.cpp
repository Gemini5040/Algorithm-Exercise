#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int a[100],pos=0;
	int t;
	while(cin>>t){
		if(t==0) break;
		a[pos++]=t;
	}
	
	for(int i=pos-1;i>=0;i--){
		cout<<a[i]<<" ";
	}
	
	return 0;
}
