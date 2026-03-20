#include <bits/stdc++.h>
using namespace std;

const int N=25;
int a[N];
int n,k;
int ans=0;

bool is_prime(int x){
	if(x<2) return false;
	for(int i=2;i<=x/i;i++){
		if(x%i==0) return false;
	}
	return true;
}

void f(int sum,int st,int t){
	for(int i=st;i<=n;i++){
		int s=sum+a[i];
		if(t==k){
			if(is_prime(s)){
//				cout<<s<<" ";
				ans++;
			}
		}else if(t<k){
			f(s,i+1,t+1);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	f(0,1,1);
	
	cout<<ans<<"\n";
	
	return 0;
}
