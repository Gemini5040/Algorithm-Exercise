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
using ll=long long;
using ull=unsigned long long;
using i128=__int128;

const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll inv2=(MOD+1)/2;
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ull rnd(ull l=0ull,ull r=-1ull){return uniform_int_distribution<ull>(l,r)(rng);}

/*
struct mint {
	int x;
	mint(int o = 0) : x(o) {}
	mint& operator=(int o) { x = o; return *this; }
	mint& operator+=(mint o) { if ((x += o.x) >= MOD) x -= MOD; return *this; }
	mint& operator-=(mint o) { if ((x -= o.x) < 0) x += MOD; return *this; }
	mint& operator*=(mint o) { x = (ll)x * o.x % MOD; return *this; }
	mint& operator^=(int b) {
		mint ret = 1, w = *this;
		for (; b; b >>= 1, w *= w) if (b & 1) ret *= w;
		x = ret.x; return *this;
	}
	mint& operator/=(mint o) { return *this *= (o ^= (MOD - 2)); }
	friend mint operator+(mint a, mint b) { return a += b; }
	friend mint operator-(mint a, mint b) { return a -= b; }
	friend mint operator*(mint a, mint b) { return a *= b; }
	friend mint operator/(mint a, mint b) { return a /= b; }
	friend mint operator^(mint a, int b) { return a ^= b; }
};
mint qpow(mint x, int y = MOD - 2) { return x ^ y; }

const int MAXN = 1e6 + 7;
mint fac[MAXN], ifac[MAXN], inv[MAXN];
void init_comb(int n) {
	fac[0] = ifac[0] = inv[1] = 1;
	for(int i = 2; i <= n; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i];
	for(int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
		ifac[i] = ifac[i - 1] * inv[i];
	}
}
mint C(int n, int k) { 
	return (k < 0 || k > n) ? 0 : fac[n] * ifac[k] * ifac[n - k]; 
}

inline mint sgn(int x) {
	return (x & 1) ? MOD - 1 : 1;
}
*/

void solve(){
	
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
