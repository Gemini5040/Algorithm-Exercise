#include <bits/stdc++.h>
using namespace std;

//#define int long long
using ll=long long;
using ull=unsigned long long;
using i128=__int128;

const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll P=1e9+7;
const ull H=1e9+7;
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int N=100010;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ull rnd(ull l=0ull,ull r=-1ull){return uniform_int_distribution<ull>(l,r)(rng);}

void solve(){
	int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(k==1){
        cout<<"YES"<<"\n";
        return;
    }

    vector<int> b=a;
    sort(b.begin(),b.end(),less<int>());
    int cutoff=b[k-2];
    vector<int> c;
    for(auto x:a){
        if(x<=cutoff){
            c.push_back(x);
        }
    }

    bool bad=false;
    int spare=c.size()-k+1;
    int l=0,r=c.size()-1;
    while(l<r){
        if(c[l]!=c[r]){
            if(spare==0){
                bad=true;
                break;
            }
            if(c[l]==cutoff){
                l++;
                spare--;
            }else if(c[r]==cutoff){
                r--;
                spare--;
            }else{
                bad=true;
                break;
            }
        }else{
            l++;
            r--;
        }
    }

    if(bad) cout<<"NO"<<"\n";
    else cout<<"YES"<<"\n";
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