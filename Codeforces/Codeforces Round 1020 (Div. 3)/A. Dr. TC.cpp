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
		string s;
		cin>>n>>s;

		int cnt=0;
		for(auto ss:s){
			if(ss=='1'){
				cnt++;
			}
		}
		
		cout<<(n-1)*cnt+(n-cnt)<<"\n";
	}
	
	return 0;
}
