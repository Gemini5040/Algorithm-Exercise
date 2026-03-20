#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=100010;
ll a[N];
ll b[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]*=a[i];
	}
	sort(a+1,a+1+n,[&](ll x,ll y){return x<y;});
	
	for(int i=m;i<=n;i++){
		b[i]=a[i]-a[i-m+1];
	}
	sort(b+m,b+1+n,[&](ll x,ll y){return x<y;});
	
	cout<<b[m]<<"\n";
	
	return 0;
}