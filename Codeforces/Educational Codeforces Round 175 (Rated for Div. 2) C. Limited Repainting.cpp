#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int k,int target,string s,vector<int> a){
	int cnt=0;
	char last='R';
	for(int i=0;i<(int)a.size();i++){
		if(a[i]>target){
			if(last=='R'&&s[i]=='B') cnt++;
			last=s[i];
		}
	}
	
	return cnt>k;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,k;
		string s;
		cin>>n>>k>>s;
		
		vector<int> a(n);
		for(int i=0;i<n;i++) cin>>a[i];
		
		int l=0,r=1e9;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(k,mid,s,a)) l=mid+1;
			else r=mid;
		}
		
		cout<<l<<"\n";
	}
	
	return 0;
}
