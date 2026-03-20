#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int Cm2(int m){
	return m*(m-1)/2;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	vector<int> cm2;
	for(int i=2;i<=500;i++){
		int t=Cm2(i);
		cm2.push_back(t);
	}
	
	int T;
	cin>>T;
	
	while(T--){
		int k;
		cin>>k;
		
		if(k==0){
			cout<<1<<"\n";
			cout<<1<<" "<<1<<"\n";
			continue;
		}
		
		vector<pair<int,int>> ans;
		int x=1,y=1;
		auto it_t=upper_bound(cm2.begin(),cm2.end(),k);
		int t=it_t-cm2.begin()+1;
		for(int i=1;i<=t;i++){
			ans.emplace_back(i,y);
		}
		it_t--;
		k-=(*it_t);
		
		while(k){
			it_t=upper_bound(cm2.begin(),cm2.end(),k);
			t=it_t-cm2.begin()+1;
			y++;
			for(int i=y;i<=y+t-2;i++){
				ans.emplace_back(x,i);
			}
			y=y+t-2;
			x++;
			it_t--;
			k-=(*it_t);
		}
		
		cout<<ans.size()<<"\n";
		for(auto [a,b]:ans){
			cout<<a<<" "<<b<<"\n";
		}
	}
	
	return 0;
}
