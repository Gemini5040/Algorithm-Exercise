#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> g(n+1,vector<int>(n+1,0));
    int x,y,num;
    while((cin>>x>>y>>num)&&x&&y&&num){
        g[x][y]=num;
    }
    vector<vector<vector<int>>> dp(2*n+1,vector<vector<int>>(n+1,vector<int>(n+1,0)));
    for(int k=2;k<=2*n;k++){
        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=n;i2++){
                int j1=k-i1,j2=k-i2;
                if(j1>=1&&j1<=n&&j2>=1&&j2<=n){
                    dp[k][i1][i2]=max({dp[k-1][i1-1][i2-1],dp[k-1][i1-1][i2],dp[k-1][i1][i2-1],dp[k-1][i1][i2]})+g[i1][j1];
                    if(i1!=i2){
                        dp[k][i1][i2]+=g[i2][j2];
                    }
                }
            }
        }
    }
    cout<<dp[2*n][n][n]<<"\n";
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