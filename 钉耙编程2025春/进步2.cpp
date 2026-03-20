#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=200010;
ll a[N],tree[N];

ll lowbit(ll x){
	return x&-x;
}

void update(ll x,ll d){
	while(x<=N){
		tree[x]+=d;
		x+=lowbit(x);
	}
}

ll sum(ll x){
	ll ans=0;
	while(x>0){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		fill(a,a+N,0);
		fill(tree,tree+N,0);
		
		int n,q;
		cin>>n>>q;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
			update(i,a[i]);
		}
		
		ll res=0;
		ll pos=1;
		while(q--){
			ll op,x,y;
			cin>>op>>x>>y;
			
			if(op==1){
				ll d=y-a[x];
				a[x]=y;
				update(x,d);
			}else if(op==2){
				ll tmp=(sum(y)/100-sum(x-1)/100)*pos;
				pos++;
				res^=tmp;
			}
		}
		
		cout<<res<<"\n";
	}
	
	return 0;
}