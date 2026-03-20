#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,q;
		cin>>n>>q;
		
		vector<ll> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		
		vector<ll> vis=a,cur=a;
		vector<pair<int,ll>> update;
		while(q--){
			int p;
			ll v;
			cin>>p>>v;
			p--;
			update.emplace_back(p,v);
			cur[p]+=v;
			vis.push_back(cur[p]);
		}
		sort(vis.begin(),vis.end());
		vis.erase(unique(vis.begin(),vis.end()),vis.end());
		
		int k=vis.size();
		vector<ll> tree(k+1,0);
		
		auto getidx=[&](ll val){
			return lower_bound(vis.begin(),vis.end(),val)-vis.begin()+1;
		};
		
		auto add=[&](int idx,ll val){
			while(idx<=k){
				tree[idx]+=val;
				idx+=idx&-idx;
			}
		};
		
		auto not_exceed=[&](ll val){
			ll res=0,idx=0;
			for(int i=20;i>=0;i--){
				if((idx|(1<<i))<=k&&res+tree[idx|(1<<i)]<=val){
					idx|=1<<i;
					res+=tree[idx];
				}
			}
			return res;
		};
		
		for(int i=0;i<n;i++){
			add(getidx(a[i]),1);
		}
		
		for(auto &[idx,val]:update){
			add(getidx(a[idx]),-1);
			a[idx]+=val;
			add(getidx(a[idx]),1);
			cout<<not_exceed((n+1)>>1)<<"\n";
		}
	}
	
	return 0;
}
