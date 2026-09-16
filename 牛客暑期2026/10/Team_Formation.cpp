#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
using ll=long long;
const int inf=0x3f3f3f3f3f3f3f3f;

void solve(){
	int n;
	cin>>n;
	int m=n*3;

	vector<vector<int>> g(m+5,vector<int>(m+5));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
		}
	}

	vector<vector<int>> vf(10);
	for(int F=0;F<(1<<m);F++){
		int tF=F;
		int cnt=0;
		while(tF){
			cnt++;
			tF-=tF&(-tF);
		}
		if(cnt%3==0){
			int t=cnt/3;
			if((F&((1<<t)-1))==((1<<t)-1)){
				vf[t].push_back(F);
			}
		}
	}

	vector<int> dp((1<<m)+5,-inf);
	dp[0]=0;
	vector<int> pos(m+5);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)vf[i].size();j++){
			int F=vf[i][j];
			for(int k=0;k<m;k++){
				if((F>>k)&1){
					pos[cnt++]=k;
				}
			}

			for(int k1=0;k1<cnt;k1++){
				for(int k2=k1+1;k2<cnt;k2++){
					for(int k3=k2+1;k3<cnt;k3++){
						int cur=(1LL<<pos[k1])+(1LL<<pos[k2])+(1LL<<pos[k3]);
						int preF=F^cur;
						int x=pos[k1]+1;
						int y=pos[k2]+1;
						int z=pos[k3]+1;
						dp[F]=max(dp[F],dp[preF]+g[x][y]+g[x][z]+g[y][z]);
					}
				}
			}

			cnt=0;
		}
	}

	cout<<dp[(1<<m)-1]<<endl;
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