#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int a,b;
	int ans=0;
	int max=0;
	for(int i=1;i<=7;i++){
		cin>>a>>b;
		int t=a+b-8;
		if(t>max){
			ans=i;
			max=t;
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
