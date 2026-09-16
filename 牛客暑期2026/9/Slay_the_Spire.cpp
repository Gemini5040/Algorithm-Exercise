#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
using ll=long long;
using ii=__int128;
const int inf=0x3f3f3f3f3f3f3f3f;

int x,a,b;

int root(int aa,int bb,int cc){
	return ceill((-bb+sqrtl((ii)bb*(ii)bb-4*(ii)aa*(ii)cc))/(2*aa));
}

int cal(int nn){
	ii n=nn;
	ii p1=a*n+n*(n-1)*(a-1)/2;
	ii p2=(a-1)*n*(1+(a-1)*n)/2;
	ii p3=(a-1)*n*b;
	int m=-1;
	ii re=x-p1;
	if(re>=0){
		if(re-p2-p3>=0){
			m=ceill(1.0*(re-p2)/b);
		}else{
			m=root(-1,2*(a-1)*n+1+2*b,-2*re);
		}
	}else{
		return -1;
	}

	return n+m;
}

void solve(){
	cin>>x>>a>>b;

	int ans=inf;
	if(a==1){
		if(a>=b){
			ans=x;
		}else{
			ans=ceill(1.0*x/b);
		}
	}else{
		if(a>=b){
			ans=root(a-1,a+1,-2*x);
		}else{
			int i=0;
			while(1){
				int res=cal(i);
				if(res==-1) break;
				ans=min(ans,res);
				i++;
			}
		}
	}

	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T=1;
	// cin>>T;

	while(T--){
		solve();
	}

	return 0;
}