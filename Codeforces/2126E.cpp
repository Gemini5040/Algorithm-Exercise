#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll P=1e9+7;
const ull H=1e9+7;
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int N=100010;

mt19937 eng(chrono::steady_clock::now().time_since_epoch().count());
ull rnd(ull l=0ull,ull r=-1ull){return uniform_int_distribution<ull>(l,r)(eng);}

void solve(){
	ll n;
    cin>>n;
    vector<ll> a(n),p(n),s(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=1;i<n;i++){
        if(p[i-1]%p[i]||s[i]%s[i-1]){
            cout<<"NO"<<"\n";
            return;
        }
    }
    if(p[n-1]!=s[0]){
        cout<<"NO"<<"\n";
        return;
    }
    ll g=p[n-1];
    for(int i=0;i<n-1;i++){
        if((ll)__gcd(p[i],s[i+1])!=g){
            cout<<"NO"<<"\n";
            return;
        }
    }
    cout<<"YES"<<"\n";
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
