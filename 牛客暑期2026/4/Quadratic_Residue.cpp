#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve(){
	int x1,x2,p,q;
	cin>>p;
	int flag=0;
	if(p==1||p==2||p==3){
		x1=p+1,x2=1,q=(p+1)*p+1;
		cout<<x1<<" "<<x2<<" "<<q<<endl;
		return;
	}
	int st=1;
	st=sqrt(2*p);
	for(int i=st;i<=p;i++){
		int pw=i*i;
		int c=pw%p,n=pw/p;
		if(n-1<1){
			continue;
		}else{
			flag=1;
			x1=i,x2=i,q=(n-1)*p+c;
			cout<<x1<<" "<<x2<<" "<<q<<endl;
			// cout<<"----------"<<endl;
			// cout<<x1*x1%q<<" "<<p%q<<endl;;
			// cout<<x2*x2%p<<" "<<q%p<<endl;
			// cout<<endl;
			return;
		}
	}
	if(!flag){
		cout<<"Impossible"<<endl;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T=1;
	cin>>T;

	while(T--){
		solve();
	}

	return 0;
}