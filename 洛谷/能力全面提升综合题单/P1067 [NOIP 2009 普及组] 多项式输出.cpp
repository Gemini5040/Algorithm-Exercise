#include <bits/stdc++.h>
using namespace std;

const int N=110;
int coefficient[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	
	for(int i=n;i>=0;i--){
		cin>>coefficient[i];
	}
	
	for(int i=n;i>=0;i--){
		if(coefficient[i]==0){
			continue;
		}else if(coefficient[i]<0){
			if(coefficient[i]!=-1||!i) cout<<coefficient[i];
			else cout<<"-";
			if(i>1) cout<<"x"<<"^"<<i;
			else if(i==1) cout<<"x";
		}else if(coefficient[i]>0){
			if(i<n) cout<<"+";
			if(coefficient[i]!=1||!i) cout<<coefficient[i];
			if(i>1) cout<<"x"<<"^"<<i;
			else if(i==1) cout<<"x";
		}
	}
	
	return 0;
}
