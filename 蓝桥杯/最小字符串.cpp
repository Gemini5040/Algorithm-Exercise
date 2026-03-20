#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	string s1,s2;
	cin>>s1>>s2;
	sort(s2.begin(),s2.end(),less<char>());
	
	int i=0,j=0;
	while(i<n&&j<m){
		if(s1[i]<=s2[j]) cout<<s1[i++];
		else cout<<s2[j++];
	}
	while(i<n) cout<<s1[i++];
	while(j<m) cout<<s2[j++];
	
	return 0;
}
