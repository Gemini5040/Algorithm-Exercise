#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		string a,b;
		cin>>a;
		for(auto i=a.end()-1;i>=a.begin();i--){
			if((*i)=='p') b+='q';
			else if((*i)=='w') b+='w';
			else if((*i)=='q') b+='p';
		}
		
		cout<<b<<"\n";
	}
	
	return 0;
}