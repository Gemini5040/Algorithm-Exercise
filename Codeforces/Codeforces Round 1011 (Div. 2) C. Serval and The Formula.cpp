#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		ll x,y;
		cin>>x>>y;
		if(x==y){
			cout<<"-1"<<"\n";
		}else{
			cout<<((1ULL<<48)-max(x,y))<<"\n";
		}
	}
	
	return 0;
}