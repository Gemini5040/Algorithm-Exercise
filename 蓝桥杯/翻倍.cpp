#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string add(string A,string B){
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	string ans;
	int lim=max(A.length(),B.length());
	int t=0;
	for(int i=0;i<lim||t;i++){
		if(i<(int)A.length()) t+=A[i]-'0';
		if(i<(int)B.length()) t+=B[i]-'0';
		int v=t%10;
		ans.push_back(v+'0');
		t/=10;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

bool cmp(string &A,string &B){
	if(A.length()!=B.length()) return A.length()<B.length();
	return A<B;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	string a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	ll cnt=0;
	for(int i=1;i<n;i++){
		while(cmp(a[i],a[i-1])){
			a[i]=add(a[i],a[i]);
			cnt++;
		}
	}
	
	cout<<cnt<<"\n";
	
	return 0;
}
