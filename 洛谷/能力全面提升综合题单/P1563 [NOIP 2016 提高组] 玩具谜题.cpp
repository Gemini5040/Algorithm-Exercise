#include <bits/stdc++.h>
using namespace std;

const int N=100010;
struct node{
	int dir;
	string job;
}a[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>a[i].dir>>a[i].job;
	}
	
	int pos=0;
	for(int i=1;i<=m;i++){
		int d,s;
		cin>>d>>s;
		if(!d){
			if(!a[pos].dir){
				pos=(n+pos-s)%n;
			}else{
				pos=(n+pos+s)%n;
			}
		}else{
			if(!a[pos].dir){
				pos=(n+pos+s)%n;
			}else{
				pos=(n+pos-s)%n;
			}
		}
	}
	
	cout<<a[pos].job<<"\n";
	
	return 0;
}
