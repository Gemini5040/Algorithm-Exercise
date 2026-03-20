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

struct node{
    ll l,r,real;
};

void solve(){
	ll n,k;
    cin>>n>>k;
    vector<node> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].l>>a[i].r>>a[i].real;
    }
    sort(a.begin(),a.end(),[&](node x,node y){
        if(x.l!=y.l) return x.l<y.l;
        return x.r<y.r;
    });
    ll ans=k;
    for(int i=0;i<n;i++){
        if(ans>=a[i].l&&ans<=a[i].r){
            ans=max(ans,a[i].real);
        }
    }

    cout<<ans<<"\n";
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
