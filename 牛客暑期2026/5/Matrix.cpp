#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void prarr(vector<vector<int>> &arr){
    int n=arr.size()-1,m=arr[0].size()-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1,vector<int>(m+1,0));

    int ma=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            ma=max(ma,g[i][j]);
        }
    }

    if(n==1||m==1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(g[i][j]!=g[1][1]){
                    cout<<-1<<endl;
                    return;
                }
            }
        }
        cout<<0<<endl;
        return;
    }

    int x=(-ma-g[n][m]+g[n-1][m]+g[n][m-1]);
    vector<vector<int>> c(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            c[i][j]=x+ma-g[i][j];
        }
    }
    // prarr(c);

	vector<vector<int>> tc(n+1,vector<int>(m+1,0));
	tc[1][1]=c[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==n&&j==m){
				continue;
			}else if(i==n){
				tc[i][j+1]+=tc[i][j];
				continue;
			}else if(j==m){
				tc[i+1][j]+=tc[i][j];
				continue;
			}
			int r=c[i][j+1]-tc[i][j+1];
			tc[i][j+1]+=r;
			int d=tc[i][j]-r;
			if(d<0||r<0){
				cout<<-1<<endl;
				return;
			}
			tc[i+1][j]+=d;
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(tc[i][j]!=c[i][j]){
				cout<<-1<<endl;
				return;
			}
		}
	}

    int ans=x+ma-g[n][m];
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

    return 0;
}
