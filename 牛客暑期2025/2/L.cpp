#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MOD=998244353;

vector<ll> getcir(vector<ll>& a){
	vector<ll> cir;
	vector<bool> st(a.size(),false);
	for(int i=1;i<(int)a.size();i++){
		if(!st[i]){
			st[i]=true;
			ll p=a[i];
			ll cnt=1;
			while(p!=i){
				cnt++;
				st[p]=true;
				p=a[p];
			}
			cir.push_back(cnt);
		}
	}
	return cir;
}

ll cn2(ll n){
	return (n*(n-1)/2)%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		vector<ll> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
		vector<ll> cir=getcir(a);
		ll odd=0;
		for(ll x:cir){
			if(x%2){
				odd++;
			}
		}
		
		ll ans=0;
		if(odd==0){
			ll tmp=1;
			bool flag=false;
			for(int i=0;i<(int)cir.size();i++){
				if(cir[i]==2){
					tmp=tmp;
				}
				else{
					if(flag) tmp=(tmp*2)%MOD;
					else flag=true;
				}
			}
			for(int i=0;i<(int)cir.size();i++){
				if(cir[i]==2) ans=(ans+(tmp*(ll)(flag?2:1))%MOD)%MOD;
				else if(cir[i]==4) ans=(ans+(tmp*4)%MOD)%MOD;
				else ans=(ans+(tmp*((cn2(cir[i])-cir[i]/4*cir[i]+cir[i]/2*(ll)(((cir[i]-2)/2)%2==1)+MOD*100LL)%MOD))%MOD)%MOD;
			}
		}else if(odd==2){
			ans=1;
			for(ll x:cir){
				if(x%2){
					ans=(ans*x)%MOD;
				}else{
					if(x==2) ans=ans;
					else ans=(ans*2)%MOD;
				}
			}
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
