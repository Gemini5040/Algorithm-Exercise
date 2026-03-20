#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int target;
	char ch;
	cin>>target>>ch;
	
	vector<int> v;
	for(int i=1;i<=1000;i++){
		int t=2*i*i-1;
		v.push_back(t);
	}
	
	auto r=upper_bound(v.begin(),v.end(),target);
	r--;
	int res=target-*r;
	
	int sum=(*r+1)/2;
	int row=sqrt(sum);
	int start=2*row-1;
	for(int i=1;i<=row;i++){
		for(int j=1;j<i;j++) cout<<" ";
		for(int j=1;j<=2*(row-i+1)-1;j++) cout<<ch;
		cout<<"\n";
	}
	for(int i=row-1;i>=1;i--){
		for(int j=1;j<i;j++) cout<<" ";
		for(int j=1;j<=2*(row-i+1)-1;j++) cout<<ch;
		cout<<"\n";
	}
	
	cout<<res<<endl;
	
	return 0;
}