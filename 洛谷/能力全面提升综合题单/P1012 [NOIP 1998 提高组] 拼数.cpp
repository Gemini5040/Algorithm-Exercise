#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int get_digit(ll x){
	if(x==0) return 1;
	int res=0;
	while(x){
		res++;
		x/=10;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	vector<ll> v;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	sort(v.begin(),v.end(),[&](ll x,ll y){
		x=x*(ll)pow(10LL,10-get_digit(x));
		y=y*(ll)pow(10LL,10-get_digit(y));
		return x>y;
	});
	sort(v.begin(),v.end(),[&](ll x,ll y){
		ll a=x*(ll)pow(10LL,10-get_digit(x))+y*(ll)pow(10LL,10-get_digit(x)-get_digit(y));
		ll b=y*(ll)pow(10LL,10-get_digit(y))+x*(ll)pow(10LL,10-get_digit(y)-get_digit(x));
		return a>b;
	});
	
	for(auto vv:v){
		cout<<vv;
	}
	
	return 0;
}
