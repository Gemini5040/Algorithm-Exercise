#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=100010;
ll tree1[N],tree2[N];

int lowbit(int x){
	return x&-x;
}

void update1(ll x,ll d){
	while(x<N){
		tree1[x]+=d;
		x+=lowbit(x);
	}
}

void update2(ll x,ll d){
	while(x<N){
		tree2[x]+=d;
		x+=lowbit(x);
	}
}

ll sum1(int x){
	ll ans=0;
	while(x>0){
		ans+=tree1[x];
		x-=lowbit(x);
	}
	return ans;
}

ll sum2(int x){
	ll ans=0;
	while(x>0){
		ans+=tree2[x];
		x-=lowbit(x);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	ll a,old=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		update1(i,a-old);
		update2(i,(i-1)*(a-old));
		old=a;
	}
	
	while(m--){
		ll op,x,y,k;
		cin>>op;
		if(op==1){
			cin>>x>>y>>k;
			update1(x,k);
			update1(y+1,-k);
			update2(x,(x-1)*k);
			update2(y+1,y*(-k));
		}else{
			cin>>x>>y;
			cout<<y*sum1(y)-sum2(y)-(x-1)*sum1(x-1)+sum2(x-1)<<"\n";
		}
	}
	
	return 0;
}
