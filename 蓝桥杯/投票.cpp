#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	
	string s;
	for(int i=0;i<n;i++){
		char tmp;
		cin>>tmp;
		s+=tmp;
	}
	
	int cnt_A=0,cnt_B=0;
	for(int i=0;i<n;i++){
		if(s[i]=='A') cnt_A++;
		else if(s[i]=='B') cnt_B++;
	}
	
	if(cnt_A>cnt_B) cout<<"A"<<"\n";
	else cout<<"B"<<"\n";
	
	return 0;
}