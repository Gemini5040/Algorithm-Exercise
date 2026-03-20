#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[25][25][25];

ll w(ll a,ll b,ll c){
	if(a>0&&a<=20&&b>0&&b<=20&&c>0&&c<=20&&dp[a][b][c]) return dp[a][b][c];
	if(a<=0||b<=0||c<=0) return 1;
	else if(a>20||b>20||c>20) return w(20,20,20);
	else if(a<b&&b<c) return dp[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else return dp[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll a,b,c;
	while(cin>>a>>b>>c){
		if(a==-1&&b==-1&&c==-1) break;
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<"\n";
	}
	
	return 0;
}
