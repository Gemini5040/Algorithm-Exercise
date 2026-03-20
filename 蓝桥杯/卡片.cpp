#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	int ans=0;
	while((ans*ans+ans)/2<n){
		ans++;
	}
	
	cout<<ans;
	
	return 0;
}