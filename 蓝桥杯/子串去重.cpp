#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string unq(string &s,int l,int r){
	l--,r--;
	string t;
	vector<int> st(300,0);
	for(int i=l;i<=r;i++){
		if(!st[s[i]-'0']){
			t+=s[i];
			st[s[i]-'0']=1;
		}
	}
	return t;
}

int cmp(string &s1,string &s2){
	int cnt=0;
	int lim=min(s1.length(),s2.length());
	if(s1.length()<s2.length()){
		cnt+=s2.length()-s1.length();
	}else{
		cnt+=s1.length()-s2.length();
	}
	for(int i=0;i<lim;i++){
		if(s1[i]!=s2[i]){
			cnt++;
		}
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	int m;
	cin>>s>>m;
	
	while(m--){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		string t1=unq(s,l1,r1);
		string t2=unq(s,l2,r2);
		int ans=cmp(t1,t2);
		cout<<ans<<"\n";
	}
	
	return 0;
}
