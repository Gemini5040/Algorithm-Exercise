#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ull B=1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin>>s;
	int n=s.length();
	
	vector<ull> hash(n+5),rehash(n+5),b(n+5,1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]*B;
	}
	for(int i=1;i<=n;i++){
		hash[i]=hash[i-1]*B+s[i-1];
	}
	for(int i=n;i>=1;i--){
		rehash[i]=rehash[i+1]*B+s[i-1];
	}
	
	auto gethash=[&](int l,int r){
		return hash[r]-hash[l-1]*b[r-l+1];
	};
	auto getrehash=[&](int l,int r){
		return rehash[l]-rehash[r+1]*b[r-l+1];
	};
	
	auto check=[&](int x){
		for(int i=1;i+x-1<n-x+1;i++){
			if(gethash(i,i+x-1)==getrehash(n-x+1,n)) return true;
		}
		for(int i=n;i-x+1>1+x-1;i--){
			if(getrehash(i-x+1,i)==gethash(1,x)) return true;
		}
		
		int L=1,R=n;
		while(s[L-1]==s[R-1]&&L<R) L++,R--;
		if(L>x) return true;
		
		int d=x-L+1;
		for(int i=R-d+1;i>L+d-1;i--){
			if(gethash(L,L+d-1)==getrehash(i,i+d-1)) return true;
		}
		for(int i=L;i+d-1<R+1;i++){
			if(gethash(i,i+d-1)==getrehash(R-d+1,R)) return true;
		}
		
		return false;
	};
	
	int l=1,r=n/2;
	while(l<r){
		int m=(l+r+1)>>1;
		if(check(m)) l=m;
		else r=m-1;
	}
	
	cout<<l<<"\n";
	
	return 0;
}
