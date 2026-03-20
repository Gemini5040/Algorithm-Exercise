#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,m,l,r;
		cin>>n>>m>>l>>r;
		int d=n-m;
		while(l<0&&d>0){
			l++;
			d--;
		}
		while(r>0&&d>0){
			r--;
			d--;
		}
		cout<<l<<" "<<r<<"\n";
	}
	
	return 0;
}