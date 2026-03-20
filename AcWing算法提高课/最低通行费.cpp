#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll=long long;

const int inf=0x3f3f3f3f;

void solve(){
    int n;
    cin>>n;

    vector<vector<int>> g(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }

    vector<vector<int>> dp(n+1,vector<int>(n+1,inf));
    dp[0][1]=0,dp[1][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+g[i][j];
        }
    }

    cout<<dp[n][n]<<"\n";
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