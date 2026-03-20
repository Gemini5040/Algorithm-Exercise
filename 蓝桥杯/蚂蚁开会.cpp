#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int int16_t

const int N=10010;
vector<vector<int>> g(N,vector<int>(N,0));

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	
	while(n--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		if(x1==x2){
			int dy=1;
			int wy=(y2-y1)/abs(y1-y2);
			for(int y=y1;(y-wy*dy)!=y2;y+=wy*dy){
				g[x1][y]++;
			}
		}else{
			int cnt=gcd(abs(x1-x2),abs(y1-y2));
			int dx=abs(x1-x2)/cnt;
			int dy=abs(y1-y2)/cnt;
			int wx=(x2-x1)/abs(x1-x2);
			int wy=0;
			if(dy!=0) wy=(y2-y1)/abs(y1-y2);
			for(int x=x1,y=y1;(x-wx*dx)!=x2;x+=wx*dx,y+=wy*dy){
				g[x][y]++;
			}
		}
	}
	
	ll ans=0;
	for(int i=0;i<=10000;i++){
		for(int j=0;j<=10000;j++){
			if(g[i][j]>=2){
				ans++;
			}
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
