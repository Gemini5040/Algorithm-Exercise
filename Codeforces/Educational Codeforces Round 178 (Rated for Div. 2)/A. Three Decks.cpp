#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int a,b,c;
		cin>>a>>b>>c;
		int s=a+b+c;
		int e=s/3;
		if(c>=e&&b<=e&&a<=e&&s%3==0){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}
	
	return 0;
}
