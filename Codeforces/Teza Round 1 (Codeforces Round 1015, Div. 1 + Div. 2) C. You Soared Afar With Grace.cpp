#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		
		vector<int> a(n+1,0),b(n+1,0);
		vector<int> apos(n+1,0),bpos(n+1,0);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			apos[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
			bpos[b[i]]=i;
		}
		
		int flag=1;
		int cnt=0;
		int mp=0;
		for(int i=1;i<=n;i++){
			if(b[i]!=a[bpos[a[i]]]){
				flag=0;
				break;
			}
			if(a[i]==b[i]){
				cnt++;
				mp=i;
			}
		}
		
		if(!flag){
			cout<<-1<<"\n";
			continue;
		}
		
		if((n&1)==1&&cnt!=1){
			cout<<-1<<"\n";
			continue;
		}
		
		if((n&1)==0&&cnt!=0){
			cout<<-1<<"\n";
			continue;
		}
		
		vector<pair<int,int>> ans;
		int p1=0,p2=0;
		if((n&1)==1){
			if(mp!=((1+n)>>1)){
				p1=mp,p2=(1+n)>>1;
				ans.emplace_back(p1,p2);
				swap(apos[a[p1]],apos[a[p2]]);
				swap(bpos[b[p1]],bpos[b[p2]]);
				swap(a[p1],a[p2]);
				swap(b[p1],b[p2]);
			}
			for(int i=1;i<=(n>>1);i++){
				if(i+bpos[a[i]]!=1+n){
					int p1=bpos[a[i]],p2=1+n-i;
					ans.emplace_back(p1,p2);
					swap(apos[a[p1]],apos[a[p2]]);
					swap(bpos[b[p1]],bpos[b[p2]]);
					swap(a[p1],a[p2]);
					swap(b[p1],b[p2]);
				}
			}
		}else{
			for(int i=1;i<=(n>>1);i++){
				if(i+bpos[a[i]]!=1+n){
					int p1=bpos[a[i]],p2=1+n-i;
					ans.emplace_back(p1,p2);
					swap(apos[a[p1]],apos[a[p2]]);
					swap(bpos[b[p1]],bpos[b[p2]]);
					swap(a[p1],a[p2]);
					swap(b[p1],b[p2]);
				}
			}
		}
		
		cout<<ans.size()<<"\n";
		for(auto [x,y]:ans){
			cout<<x<<" "<<y<<"\n";
		}
	}
	
	return 0;
}
