#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin>>s;
	
	int sum=0;
	int w=1;
	int lim=s.size();
	for(int i=0;i<lim-2;i++){
		if(isdigit(s[i])){
			sum=(sum+(s[i]-'0')*w)%11;
			w++;
		}
	}
	
	if(sum==10){
		if(s[lim-1]=='X'){
			cout<<"Right"<<"\n";
		}else{
			for(int i=0;i<lim-1;i++){
				cout<<s[i];
			}
			cout<<"X"<<"\n";
		}
	}else{
		if(s[lim-1]-'0'==sum){
			cout<<"Right"<<"\n";
		}else{
			for(int i=0;i<lim-1;i++){
				cout<<s[i];
			}
			cout<<sum<<"\n";
		}
	}
	
	return 0;
}
