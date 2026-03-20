#include <bits/stdc++.h>
using namespace std;

const int N=10010;
string line,s1[N],s2[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int l1=0;
	while(getline(cin,line)&&line!="EOF"){
		for(auto i:line){
			if(i=='<'){
				if(s1[l1].size()) s1[l1].pop_back();
				continue;
			}
			s1[l1].push_back(i);
		}
		l1++;
	}
	int l2=0;
	while(getline(cin,line)&&line!="EOF"){
		for(auto i:line){
			if(i=='<'){
				if(s2[l2].size()) s2[l2].pop_back();
				continue;
			}
			s2[l2].push_back(i);
		}
		l2++;
	}
	int cnt=0;
	for(int i=0;i<l1;i++){
		int size1=s1[i].size(),size2=s2[i].size();
		for(int j=0,k=0;j<min(size1,size2);j++,k++){
			if(s1[i][j]==s2[i][k]) cnt++;
		}
	}
	double t;
	cin>>t;
	int ans=round(cnt*60/t);
	
	cout<<ans<<"\n";
	
	return 0;
}
