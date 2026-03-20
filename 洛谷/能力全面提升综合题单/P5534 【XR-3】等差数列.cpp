#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll a1,a2,n;
	cin>>a1>>a2>>n;
	ll d=a2-a1;
	
	ll ans=a1*n+n*(n-1)/2*d;
	cout<<ans<<"\n";
	
	return 0;
}
