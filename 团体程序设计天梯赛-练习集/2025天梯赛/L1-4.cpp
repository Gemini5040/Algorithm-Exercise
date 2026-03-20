#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin>>n;
	
	int w=0;
	for(int i=40;i>=0;i--){
		if(n>>i&1){
			w=i;
			break;
		}
	}
	
	cout<<(1LL<<w)<<"\n";
	
	return 0;
}
