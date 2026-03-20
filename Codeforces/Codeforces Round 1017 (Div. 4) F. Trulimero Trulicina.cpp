#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		int a[n+1][m+1];
		if(n%k!=0){
			int num=1;
			for(int j=1;j<=m;j++){
				for(int i=1;i<=n;i++){
					a[i][j]=num++;
					if(num==k+1) num=1;
				}
			}
		}else if(m%k!=0){
			int num=1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					a[i][j]=num++;
					if(num==k+1) num=1;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				int num=i;
				for(int j=1;j<=m;j++){
					a[i][j]=(num++)%k+1;
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}
