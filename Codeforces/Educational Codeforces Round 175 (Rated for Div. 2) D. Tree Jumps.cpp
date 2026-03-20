#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod=998244353;

int add(int x,int y){
	if((x+y)>=0) return (x+y)%mod;
	else return (x+y)%mod+mod;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		
		vector<int> father(n+1),d(n+1);
		vector<vector<int>> layer(n+1);
		father[1]=0,d[1]=1;
		layer[0].push_back(0),layer[1].push_back(1);
		for(int i=2;i<=n;i++){
			cin>>father[i];
			d[i]=d[father[i]]+1;
			layer[d[i]].push_back(i);
		}
		
		vector<int> cnt(n+1,0),cnt_l(n+1,0);
		cnt[1]=cnt_l[1]=1;
		for(int i=2;i<=n;i++){
			if(!layer[i].size()) break;
			for(auto j:layer[i]){
				cnt[j]=add(cnt_l[i-1],((i==2)?0:-cnt[father[j]]));
				cnt_l[i]=add(cnt_l[i],cnt[j]);
			}
		}
		
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=add(ans,cnt[i]);
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
