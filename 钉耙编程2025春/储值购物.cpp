#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int v,w;
		cin>>v>>w;
		
		int cost=min(w/2+1,v);
		int cnt=v/cost;
		int res=v%cost;
		if(res&&res>w-cost){
			cnt++;
		}
		
		cout<<cnt<<"\n";
	}
	
	return 0;
}
