#include <bits/stdc++.h>
using namespace std;

const int N=1010;
bitset<2000> g[N][N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		
		vector a(n+1,vector<int>(m+1));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				a[i][j]--;
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				g[i][j].reset();
				g[i][j]=g[i][j-1];
				g[i][j][a[i][j]]=1;
			}
		}
		
		int ans=0;
		bitset<2000> s;
		for(int j=1;j<=m;j++){
			s.reset();
			for(int i=1;i<=n;i++){
				s|=g[i][j];
				if((int)s.count()==k){
					ans+=n-i+1;
					break;
				}
			}
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
