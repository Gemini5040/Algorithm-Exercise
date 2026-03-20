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
		string s;
		cin>>s;
		
		vector<int> a;
		
		for(auto ss:s){
			int t=ss-'0';
			a.push_back(t);
		}
		sort(a.begin(),a.end(),[&](int x,int y){return x<y;});
		
		vector<int> ans;
		for(int i=9;i>=0;i--){
			int target=i;
			auto pos=lower_bound(a.begin(),a.end(),target);
			ans.push_back((*pos));
			a.erase(pos,pos+1);
		}
		
		for(auto i:ans){
			cout<<i;
		}
		cout<<"\n";
	}
	
	return 0;
}
