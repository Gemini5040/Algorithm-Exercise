/*
Code::Blocks记得处理：
#define endl "\n"
cout.tie(0);
system("pause");
*/
#include <bits/stdc++.h>
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <bitset>
#include <array>
#include <tuple>
#include <iomanip>
#include <random>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
*/
using namespace std;

//#define int long long
//#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll P=1e9+7;
const ull H=1e9+7;
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int N=100010;

namespace FastIO {
    int fastio_digit[67], fastio_len = 0;
    template <typename T> inline T read() { T x = 0, w = 0; char ch = getchar(); while (ch < '0' || ch > '9') w |= (ch == '-'), ch = getchar(); while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar(); return w ? -x : x; }
    template <typename T> inline void write(T x) { if (!x) return (void)putchar('0'); while (x) fastio_digit[++fastio_len] = x % 10, x /= 10; while (fastio_len > 0) putchar(fastio_digit[fastio_len--] ^ '0'); }
    template <typename T> inline void print(T x) { if (x >= 0) write<T>(x); else putchar('-'), write<T>(-x); }
    template <typename T> inline void print(T x, char en) { print<T>(x), putchar(en); }
}; using namespace FastIO;

mt19937 eng(chrono::steady_clock::now().time_since_epoch().count());
ull rnd(ull l=0ull,ull r=-1ull){return uniform_int_distribution<ull>(l,r)(eng);}

ll n,m;

vector<ll> cal(vector<ll>& a,ll pos){
    vector<ll> res;
    res.push_back(a[pos+1]-a[pos]);
    ll fg=n/2-1;
    vector<bool> st(n,false);
    st[pos]=true,st[pos+1]=true;
    for(int i=0;i<n&&fg>0;i++){
        if(!st[i]){
            res.push_back(a[i]);
            st[i]=true;
            fg--;
        }
    }
    fg=n/2-1;
    ll p=1;
    for(int i=n-1;i>=0&&fg>0;i--){
        if(!st[i]){
            res[p]-=a[i];
            p++;
            st[i]=true;
            fg--;
        }
    }
    return res;
}

vector<ll> cmp(vector<ll> a,vector<ll> b){
    int flag=0;
    for(int i=0;i<(int)a.size();i++){
        if(a[i]!=b[i]){
            flag=(a[i]<b[i]);
            break;
        }
    }
    if(flag) return a;
    else return b;
}

vector<ll> cal_even(vector<ll>& a){
    vector<ll> b(n-1);
    for(int i=1;i<n;i++){
        b[i-1]=a[i]-a[i-1];
    }
    ll mn=INF;
    for(int i=0;i<n-1;i++){
        mn=min(mn,b[i]);
    }
    vector<ll> c;
    for(int i=0;i<n-1;i++){
        if(b[i]==mn){
            c.push_back(i);
        }
    }
    ll pos1=-1,pos2=-1;
    mn=INF;
    for(int i=0;i<(int)c.size();i++){
        if((ll)abs(c[i]-((n-1)/2))<mn){
            pos1=c[i];
            mn=(ll)abs(c[i]-((n-1)/2));
        }else if((ll)abs(c[i]-((n-1)/2))==mn){
            pos2=c[i];
            break;
        }
    }
    if(pos2==-1) return cal(a,pos1);
    else return cmp(cal(a,pos1),cal(a,pos2));
}

void solve(){
    cin>>n>>m;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),less<ll>());

    vector<ll> arr;
    if(n%2){
        if(a[0]!=0){
            ll p1=0,p2=0;
            for(int i=0;i<=n/2;i++){
                p1=(p1*m+a[i])%MOD;
            }
            for(int i=n-1;i>n/2;i--){
                p2=(p2*m+a[i])%MOD;
            }
            ll ans=(p1-p2+MOD)%MOD;
            cout<<ans<<"\n";
            return;
        }else{
            vector<ll> tarr;
            tarr.push_back(a[1]*m-a[n-1]);
            for(int i=2;i<=n/2;i++){
                tarr.push_back(a[i]);
            }
            ll p=1;
            for(int i=n-2;i>n/2;i--){
                tarr[p]-=a[i];
                p++;
            }
            a.erase(a.begin(),a.begin()+1);
            n--;
            arr=cmp(tarr,cal_even(a));
        }
    }else{
        arr=cal_even(a);
    }
    ll ans=0;
    for(int i=0;i<(int)arr.size();i++){
        ans=(ans*m+arr[i])%MOD;
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
	
//	system("pause");
	return 0;
}
