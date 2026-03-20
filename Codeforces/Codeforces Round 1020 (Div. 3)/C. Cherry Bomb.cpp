#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=200010;
struct node{
	ll a,b;
};
node v[N];

int compare(const void *x,const void *y){
	return ((node*)y)->a-((node*)x)->a;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		fill(v,v+N,(node){0,0});
		
		ll n,k;
		cin>>n>>k;
		
		set<int> s;
		for(int i=0;i<n;i++){
			cin>>v[i].a;
		}
		for(int i=0;i<n;i++){
			cin>>v[i].b;
			if(v[i].b!=-1){
				s.insert(v[i].a+v[i].b);
			}
		}
		qsort(v,n,sizeof(node),compare);
		
//		cout<<"*******\n";
//		for(int i=0;i<n;i++){
//			cout<<v[i].a<<" ";
//		}
//		cout<<"\n********\n";
		
		if((int)s.size()>1){
			cout<<0<<"\n";
		}else if((int)s.size()==1){
			ll t=*(s.begin());
			ll d=t-v[n-1].a;
//			cout<<"--"<<"d"<<":"<<d<<"\n";
			if(d<=k&&t>=v[0].a){
				cout<<1<<"\n";
			}else{
				cout<<0<<"\n";
			}
		}else{
			ll d=v[0].a-v[n-1].a;
//			cout<<"--"<<"d"<<":"<<d<<"\n";
			if(d<=k){
				cout<<k-d+1<<"\n";
			}else{
				cout<<0<<"\n";
			}
		}
	}
	
	return 0;
}
