#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> v;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		v.clear();
		
		int n,x;
		cin>>n>>x;
		
		for(int i=0;i<=x-1;i++){
			v.push_back(i);
		}
		for(int i=x+1;i<=n-1;i++){
			v.push_back(i);
		}
		if(x<=n-1) v.push_back(x);
		
		for(auto i:v){
			cout<<i<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
