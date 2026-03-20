#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int len,q;
	string s1;
	cin>>len>>q>>s1;
	
	while(q--){
		string s2;
		int a;
		cin>>s2>>a;
		vector<ll> arr(s2.length()+5,0);
		ll ans=0;
		for(int i=0;i<(int)s2.length();i++){
			if(s1[a-1+i]==s2[i]){
				arr[i]=1;
			}
		}
		ll l=0,r=-1;
		for(int i=0;i<(int)s2.length();i++){
			if(arr[i]==0&&arr[i+1]==1){
				l=i+1;
			}else if(arr[i]==1&&arr[i+1]==0){
				r=i;
				ans+=(1+(r-l+1))*(r-l+1)/2;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
