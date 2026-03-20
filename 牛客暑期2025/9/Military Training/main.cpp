#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
using ll=long long;

void solve(){
	ll sx1,sy1,sx2,sy2,tx1,ty1,tx2,ty2;
	cin>>sx1>>sy1>>sx2>>sy2>>tx1>>ty1>>tx2>>ty2;
	double sx,sy,tx,ty;
	if(sy1==sy2){
		sy=sy1,sx=max(sx1,sx2);
	}else if(sx1==sx2){
		sy=(sy1+sy2)/2.0,sx=sx1+0.5;
	}
	if(ty1==ty2){
		ty=ty1,tx=max(tx1,tx2);
	}else if(tx1==tx2){
		ty=(ty1+ty2)/2.0,tx=tx1+0.5;
	}
	double a1=1.0*abs(ty-tx-sy+sx);
	double a2=1.0*abs(ty+tx-sy-sx);
	ll ans=round(a1+a2);
	//cout<<sx<<" "<<sy<<" "<<tx<<" "<<ty<<endl;
	cout<<ans<<endl;
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
	
	//system("pause");
	return 0;
}

/*
11
0 0 0 1 0 0 0 1
0 0 1 0 0 0 0 1
0 0 0 1 1 1 0 1
0 0 0 1 1 1 1 0
0 0 0 1 0 0 -1 0
0 0 1 0 0 1 -1 1
0 0 -1 0 40 50 40 51
1 2 2 2 3 1 4 1
0 0 0 1 1000000000 1000000000 1000000000 999999999
0 0 0 1 1000000000 1000000000 999999999 1000000000
715373480 -236095205 715373481 -236095205 -365369287 -749812458 -365369286 -749812458

*/

