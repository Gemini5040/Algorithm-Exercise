#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll=long long;

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> g(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }

    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+g[i][j];
        }
    }

    cout<<dp[n][m]<<"\n";
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