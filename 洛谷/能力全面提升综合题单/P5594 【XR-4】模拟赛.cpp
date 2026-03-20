#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	vector<set<int>> v(1010);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int d;
			cin>>d;
			v[d].insert(j);
		}
	}
	
	for(int i=1;i<=k;i++){
		cout<<v[i].size()<<" ";
	}
	
	return 0;
}
