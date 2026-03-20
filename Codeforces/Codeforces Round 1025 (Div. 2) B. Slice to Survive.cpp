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
		int n,m,a,b;
		cin>>n>>m>>a>>b;
		
		vector<pair<int,int>> cd{
			make_pair(n-a+1,m),
			make_pair(n,b),
			make_pair(a,m),
			make_pair(n,m-b+1)
		};
		
		int ans=n+m;
		for(auto [x,y]:cd){
			int res=0;
			while(x>1){
				x=(x+1)>>1;
				res++;
			}
			while(y>1){
				y=(y+1)>>1;
				res++;
			}
			ans=min(ans,res);
		}
		
		cout<<1+ans<<"\n";
	}

	return 0;
}
