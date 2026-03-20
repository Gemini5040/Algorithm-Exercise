#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node{
	int id,s,w;
};

bool cmp(node x,node y){
	if(x.s!=y.s) return x.s>y.s;
	return x.id<y.id;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,r,q;
	cin>>n>>r>>q;
	
	vector<node> a(2*n);
	for(int i=0;i<2*n;i++){
		cin>>a[i].s;
	}
	for(int i=0;i<2*n;i++){
		cin>>a[i].w;
		a[i].id=i+1;
	}
	sort(a.begin(),a.end(),[&](node x,node y){
		if(x.s!=y.s) return x.s>y.s;
		return x.id<y.id;
	});
	
	vector<node> win(n),lose(n);
	int w=0,l=0;
	for(int i=1;i<=r;i++){
		w=0,l=0;
		for(int j=0;j<2*n;j+=2){
			if(a[j].w>a[j+1].w){
				a[j].s++;
				win[w++]=a[j];
				lose[l++]=a[j+1];
			}else if(a[j].w<a[j+1].w){
				a[j+1].s++;
				win[w++]=a[j+1];
				lose[l++]=a[j];
			}
		}
		
		w=0,l=0;
		int p=0;
		while(w<n&&l<n){
			if(cmp(win[w],lose[l])) a[p++]=win[w++];
			else a[p++]=lose[l++];
		}
		while(w<n) a[p++]=win[w++];
		while(l<n) a[p++]=lose[l++];
	}
	
	cout<<a[q-1].id<<"\n";
	
	return 0;
}
