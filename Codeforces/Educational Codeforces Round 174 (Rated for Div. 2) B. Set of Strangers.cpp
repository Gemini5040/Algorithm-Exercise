#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(vector<vector<int>> &a,int x,int y){
	return a[x][y]!=a[x-1][y]&&a[x][y]!=a[x+1][y]&&a[x][y]!=a[x][y-1]&&a[x][y]!=a[x][y+1];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,m;
		cin>>n>>m;
		
		vector<vector<int>> a(n+10,vector<int>(m+10,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		
		vector<int> b(n*m+10,0);
		int flag=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(check(a,i,j)&&b[a[i][j]]==0){
					b[a[i][j]]=1;
				}else if(!check(a,i,j)){
					b[a[i][j]]=2;
					flag=2;
				}
			}
		}
		
		ll sum=0;
		for(int i=0;i<=n*m;i++){
			sum=1LL*b[i]+sum;
		}
		
		cout<<sum-flag<<"\n";
	}
	
	return 0;
}
