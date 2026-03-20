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
		int n;
		cin>>n;
		
		for(int i=0;i<=9;i++){
			string s=to_string(n-i);
			int ma=0;
			for(auto c:s){
				if(c-'0'<=7){
					ma=max(ma,c-'0');
				}
			}
			if(ma+i>=7){
				cout<<i<<"\n";
				break;
			}
		}
	}
	
	return 0;
}
