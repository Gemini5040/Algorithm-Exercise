#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	m=m*3/2;
	
	vector<pair<int,int>> a;
	vector<int> b;
	for(int i=1;i<=n;i++){
		int t1,t2;
		cin>>t1>>t2;
		a.emplace_back(t1,t2);
		b.push_back(t2);
	}
	sort(a.begin(),a.end(),[&](pair<int,int> x,pair<int,int> y){
		if(x.second!=y.second) return x.second>y.second;
		return x.first<y.first;
	});
	sort(b.begin(),b.end(),[&](int x,int y){return x>y;});
	
	int cnt=m;
	for(int i=m;i<(int)b.size();i++){
		if(b[i]>=b[m-1]) cnt++;
		else break;
	}
	
	cout<<b[m-1]<<" "<<cnt<<"\n";
	for(int i=0;i<cnt;i++){
		cout<<a[i].first<<" "<<a[i].second<<"\n";
	}
	
	return 0;
}
