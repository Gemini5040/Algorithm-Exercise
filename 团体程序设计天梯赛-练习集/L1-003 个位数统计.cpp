#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string n;
	cin>>n;
	int num[10]={0};
	
	int size=n.size();
	for(auto i=0;i<size;i++){
		int t=n[i]-'0';
		num[t]++;
	}
	
	for(int i=0;i<=9;i++){
		if(num[i]!=0) cout<<i<<':'<<num[i]<<endl;
	}
	
	return 0;
}