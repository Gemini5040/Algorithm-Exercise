#include <bits/stdc++.h>
using namespace std;

const int N=1000010;
int bb[N];
int t[N];
int ta[N];
int at[N];


int find(int x){
	return x==t[x]?x:t[x]=find(t[x]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,q;
		cin>>n>>q;
		
		iota(bb+1,bb+1+n,1);
		iota(t+1,t+1+n,1);
		iota(ta+1,ta+1+n,1);
		iota(at+1,at+1+n,1);
		
		while(q--){
			int op;
			cin>>op;
			int a,b;
			switch(op){
				case 1:{
					cin>>a>>b;
					a=ta[a];
					b=ta[b];
					t[find(b)]=find(a);
					break;
				}
				case 2:{
					cin>>a>>b;
					b=ta[b];
					bb[a]=b;
					break;
				}
				case 3:{
					cin>>a>>b;
					a=ta[a];
					b=ta[b];
					swap(ta[at[a]],ta[at[b]]);
					swap(at[a],at[b]);
					break;
				}
				case 4:{
					cin>>a;
					cout<<at[find(bb[a])]<<"\n";
					break;
				}
				default:{
					break;
				}
			}
		}
	}
	
	return 0;
}