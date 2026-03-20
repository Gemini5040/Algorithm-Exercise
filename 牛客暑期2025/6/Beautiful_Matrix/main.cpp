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

void solve(){
	ll n,m;
	cin>>n>>m;
	n=n*(n-1)%MOD;
	ll k=n,r=1,ans=1;
	for(ll i=1;i<=m;i++){
		ll t=MOD-2,e=i;
		while(t){
			if(t%2) r=r*e%MOD;
			t=t/2;
			e=e*e%MOD;
		}
		ans=(ans+k*r)%MOD;
		k=k*(n+i)%MOD;
	}
	cout<<ans<<"\n";
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
	
//	system("pause");
	return 0;
}

