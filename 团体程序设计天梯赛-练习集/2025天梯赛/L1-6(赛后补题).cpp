#include <bits/stdc++.h>
using namespace std;

const int N=100010;
int a[N];
string s1,s2,s3;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	string s1;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s1+=a[i]+'a'-1;
	}
	
	while(m--){
		s2.clear();
		s3.clear();
		
		int op;
		cin>>op;
		if(op==1){
			int L1,L2;
			cin>>L1;
			for(int i=1;i<=L1;i++){
				int t;
				cin>>t;
				s2+=t+'a'-1;
			}
			cin>>L2;
			for(int i=1;i<=L2;i++){
				int t;
				cin>>t;
				s3+=t+'a'-1;
			}
			auto pos=s1.find(s2);
			if(pos<(int)s1.size()) s1.replace(pos,L1,s3);
		}else if(op==2){
			for(int i=0;i<(int)s1.size()-1;i++){
				int na=s1[i]-'a'+1,nb=s1[i+1]-'a'+1;
				if(((na+nb)>>0&1)==0){
					char nc=((na+nb)>>1)+'a'-1;
					s1.insert(s1.begin()+i+1,nc);
					i++;
				}
			}
		}else if(op==3){
			int st,ed;
			cin>>st>>ed;
			reverse(s1.begin()+st-1,s1.begin()+ed);
		}
	}
	
	int fg=0;
	for(auto ss:s1){
		if(fg) cout<<" ";
		fg=1;
		cout<<ss-'a'+1;
	}
	
	return 0;
}
