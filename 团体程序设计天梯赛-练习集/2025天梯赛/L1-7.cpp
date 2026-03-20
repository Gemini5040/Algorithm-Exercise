#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin>>n;
	
	int p=1,num=1;
	int flag=0;
	for(int i=31;i>=1;i--){
		flag=0;
		ll ans=0;
		for(int j=1;j<=(1LL<<31);j++){
			ans+=(ll)pow(j,i);
			if(ans==n){
				flag=1;
				p=i,num=j;
				break;
			}else if(ans>n){
				break;
			}
		}
		if(flag){
			break;
		}
	}
	
	if(flag){
		int f=0;
		for(int i=1;i<=num;i++){
			if(f) cout<<"+";
			f=1;
			cout<<i<<"^"<<p;
		}
	}else{
		cout<<"Impossible for "<<n<<".";
	}
	
	return 0;
}
