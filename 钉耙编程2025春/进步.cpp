#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=200010;
ll a[N];
ll tree1[N],tree2[N];
ll res[N];

ll lowbit(ll x){
	return x&-x;
}

void update1(ll x,ll d){
	while(x<=N){
		tree1[x]+=d;
		x+=lowbit(x);
	}
}

void update2(ll x,ll d){
	while(x<=N){
		tree2[x]+=d;
		x+=lowbit(x);
	}
}

ll sum1(ll x){
	ll ans=0;
	while(x>0){
		ans+=tree1[x];
		x-=lowbit(x);
	}
	return ans;
}

ll sum2(ll x){
	ll ans=0;
	while(x>0){
		ans+=tree2[x];
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
		fill(tree1,tree1+N,0);
		fill(tree2,tree2+N,0);
		fill(res,res+N,0);
		
		int n,q;
		cin>>n>>q;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ll d=a[i]-a[i-1];
			update1(i,d);
			update2(i,(i-1)*d);
		}
		
		ll pos=1LL;
		while(q--){
			ll op,x,y;
			cin>>op>>x>>y;
			if(op==1){
				ll d=y-a[x];
				a[x]=y;
				update1(x,d);
				update1(x+1,-d);
				update2(x,(x-1)*d);
				update2(x+1,x*(-d));
			}else if(op==2){
				res[pos]=((y*sum1(y)-sum2(y))/100-((x-1)*sum1(x-1)-sum2(x-1))/100)*pos;
				pos++;
			}
		}
		
		ll r=res[1]*1LL;
		for(ll i=2;i<pos;i++){
			r=r^(res[i]*1LL);
		}
		
		cout<<r<<"\n";
	}
	
	return 0;
}