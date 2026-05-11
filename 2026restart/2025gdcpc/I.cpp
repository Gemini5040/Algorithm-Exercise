#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl "\n"
using namespace std;

//#define int long long
// using ll=long long;
// using ull=unsigned long long;
// using i128=__int128;

// const int inf=0x3f3f3f3f;
// const ll MOD=998244353;
// const ll inv2=(MOD+1)/2;
// const ll P=1e9+7;
// const ull H=1e9+7;
// const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
// const int N=100010;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// ull rnd(ull l=0ull,ull r=-1ull){return uniform_int_distribution<ull>(l,r)(rng);}

int cnt1[1000006],cnt2[1000005],cnt3[1000005];
int a[100005],b[100006],c[100005];
void solve(){
	int n,ans=0;
    cin>>n;
    map<pair<int,int>,int>mp1,mp2,mp3;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        cnt1[a[i]]++;
        cnt2[b[i]]++;
        cnt3[c[i]]++;
        mp1[{b[i],c[i]}]++;
        mp2[{a[i],c[i]}]++;
        mp3[{a[i],b[i]}]++;
    }
    for (int i=1;i<=n;i++)
    {
        int aa=cnt1[a[i]];
        int bb=cnt2[b[i]];
        int cc=mp3[{a[i],b[i]}];

        ans+=(cnt1[a[i]]-1)*(cnt2[b[i]]-1)+3+(cnt2[b[i]]-1)*(cnt3[c[i]]-1)+(cnt1[a[i]]-1)*(cnt3[c[i]]-1);
        ans-=cc;
        // ans+=(aa-cc-1)*(bb-1)+(bb-cc-1)*(aa-1)-(aa-cc-1)*(bb-cc-1)+cc*cc;
        // cout<<(aa-cc-1)*(bb-1)+(bb-cc-1)*(aa-1)-(aa-cc-1)*(bb-cc-1)+cc*cc<<endl;

        aa=cnt1[a[i]];
        bb=cnt3[c[i]];
        cc=mp2[{a[i],c[i]}];
        ans-=cc;
        // ans+=(aa-cc-1)*(bb-1)+(bb-cc-1)*(aa-1)-(aa-cc-1)*(bb-cc-1)+cc*cc;
        // cout<<(aa-cc-1)*(bb-1)+(bb-cc-1)*(aa-1)-(aa-cc-1)*(bb-cc-1)+cc*cc<<endl;

        aa=cnt2[b[i]];
        bb=cnt3[c[i]];
        cc=mp1[{b[i],c[i]}];
        ans-=cc;
        // ans+=(aa-cc-1)*(bb-1)+(bb-cc-1)*(aa-1)-(aa-cc-1)*(bb-cc-1)+cc*cc;
        // cout<<(aa-cc-1)*(bb-1)+(bb-cc-1)*(aa-1)-(aa-cc-1)*(bb-cc-1)+cc*cc<<endl;

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