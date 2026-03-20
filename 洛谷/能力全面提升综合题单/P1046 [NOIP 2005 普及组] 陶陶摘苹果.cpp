#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int a[10];
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	int h;
	cin>>h;
	
	int ans=0;
	for(int i=0;i<10;i++){
		if(h+30>=a[i]) ans++;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
