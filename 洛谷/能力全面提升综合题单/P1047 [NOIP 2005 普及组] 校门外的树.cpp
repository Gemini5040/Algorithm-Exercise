#include <bits/stdc++.h>
using namespace std;

const int N=10010;
int a[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	fill(a,a+N,1);
	
	int l,m;
	cin>>l>>m;
	
	while(m--){
		int st,ed;
		cin>>st>>ed;
		fill(a+st,a+ed+1,0);
	}
	
	int ans=0;
	for(int i=0;i<=l;i++){
		if(a[i]) ans++;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
