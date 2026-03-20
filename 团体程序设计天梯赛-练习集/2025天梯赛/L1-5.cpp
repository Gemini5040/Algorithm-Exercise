#include <bits/stdc++.h>
using namespace std;

int score[30];
int cnt[30];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin>>s;
	for(int i=1;i<=26;i++){
		cin>>score[i];
	}
	
	for(auto ss:s){
		cnt[ss-'a'+1]++;
	}
	
	int ans=0;
	for(int i=1;i<=26;i++){
		ans+=score[i]*cnt[i];
	}
	
	for(int i=1;i<=26;i++){
		if(i<26) cout<<cnt[i]<<" ";
		else cout<<cnt[i];
	}
	cout<<"\n";
	cout<<ans<<"\n";
	
	return 0;
}
