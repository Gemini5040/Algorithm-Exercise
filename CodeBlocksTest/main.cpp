#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
using ll=long long;
const int INF=LONG_LONG_MAX;

void solve(){
	int n;
	cin>>n;
	int m=n*3;
	vector<vector<int>> g(m+5,vector<int>(m+5,0));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
		}
	}

	vector<int> dp(1LL<<m,-INF);
	vector<vector<int>> s(10,vector<int>());
	dp[0]=0;
	for(int F=0;F<(1LL<<m);F++){
		int cnt=0;
		int tF=F;
		while(tF){
			cnt+=tF&1;
			tF>>=1;
		}
		if(cnt%3==0){
			s[cnt/3].push_back(F);
		}
	}

	// dp[0]=0;
	// for(int i=1;i<=n;i++){
	// 	for(int j=0;j<(int)s[i].size();j++){
	// 		for(int k=0;k<(int)s[1].size();k++){
	// 			int curF=s[i][j];
	// 			int cur=s[1][k];
	// 			int preF=curF^cur;

	// 			if(preF==curF-cur){
	// 				vector<int> pos;
	// 				for(int p=0;p<m;p++){
	// 					if((cur>>p)&1){
	// 						pos.push_back(p+1);
	// 					}
	// 				}

	// 				int x=pos[0];
	// 				int y=pos[1];
	// 				int z=pos[2];
	// 				dp[curF]=max(dp[curF],dp[preF]+g[x][y]+g[x][z]+g[y][z]);
	// 			}
	// 		}
	// 	}
	// }

	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)s[i].size();j++){
			int F=s[i][j];
			vector<int> sl;
			for(int k=0;k<n;k++){
				if((F>>k)&1){
					sl.push_back(k);
				}
			}

			for(int k1=0;k1<i*3;k1++){
				for(int k2=k1+1;k2<i*3;k2++){
					for(int k3=k2+1;k2<i*3;k3++){
						int cur=(1LL<<sl[k1])+(1LL<<sl[k2])+(1LL<<sl[k3]);
						int preF=F^cur;
						int x=sl[k1]+1;
						int y=sl[k2]+2;
						int z=sl[k3]+3;
						dp[F]=max(dp[F],dp[preF]+g[x][y]+g[x][z]+g[y][z]);
					}
				}
			}

		}
	}

	cout<<dp[(1LL<<m)-1]<<endl;
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
