#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		
		vector<int> p(n+1,0);
		for(int i=1;i<=n;i++){
			cin>>p[i];
		}
		
		set<int> x;
		for(int i=1;i<=n;i++){
			int d;
			cin>>d;
			while(!x.count(d)){
				x.insert(d);
				d=p[d];
			}
			cout<<x.size()<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
