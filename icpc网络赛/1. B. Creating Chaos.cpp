#include <bits/stdc++.h>
using namespace std;

using ll=long long;

void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cout<<i<<" \n"[i==k];
    }
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