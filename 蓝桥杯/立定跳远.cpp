#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=100010;
int n,m;
vector<int> a(N);

bool check(int x){
	int last,gap;
	int cnt=0;
	for(int i=1;i<=n;i++){
		last=a[i-1];
		gap=a[i]-a[i-1];
		if(gap>x){
			while(a[i]-last>x){
				last+=x;
				cnt++;
				if(cnt>m+1) return true;
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int l=0,r=1e9;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	
	cout<<l<<"\n";
	
	return 0;
}
