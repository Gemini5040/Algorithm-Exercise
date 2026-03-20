#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin>>s;
	
	reverse(s.begin(),s.end());
	
	int lim=s.size();
	int flag=0;
	if(s[lim-1]=='-') cout<<"-";
	for(int i=0;i<lim;i++){
		if(isdigit(s[i])){
			if(!flag&&s[i]>'0'){
				flag=1;
			}
			if(flag){
				cout<<s[i];
			}
		}
	}
	if(lim==1&&s[0]=='0') cout<<"0";
	
	return 0;
}
