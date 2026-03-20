#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		
		vector<ll> b(2*n);
		for(auto &x:b) cin>>x;
		sort(b.begin(),b.end(),[&](ll x,ll y){return x>y;});
		
		int flag=1;
		for(int i=1;i<2*n-1;i++){
			if(flag){
				swap(b[i],b[i+1]);
			}
			flag=1-flag;
		}
		
		int num=0;
		for(int i=1;i<2*n-1;i+=2){
			num+=b[i]-b[i+1];
		}
		num=b[0]-num+b[2*n-1];
		
		vector<ll> a;
		for(int i=0;i<2*n-1;i++){
			a.push_back(b[i]);
		}
		a.push_back(num);
		a.push_back(b[2*n-1]);
		
		for(int i=0;i<=2*n;i++){
			cout<<a[i]<<" \n"[i==2*n];
		}
	}
	
	return 0;
}
