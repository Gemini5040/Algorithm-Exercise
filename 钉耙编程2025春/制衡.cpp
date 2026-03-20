#include <bits/stdc++.h>
using namespace std;

const int N=1000010;
int f[N];
int cf[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		memset(f,0,sizeof(f));
		memset(cf,0,sizeof(cf));
		
		int n,k;
		cin>>n>>k;
		
		for(int i=1;i<=n;i++){
			
			for(int j=1;j<=k;j++){
				cf[j]=f[j];
			}

			int m=cf[1];
			for(int j=1;j<=k;j++){
				m=max(m,cf[j]);
				int t;
				cin>>t;
				f[j]=m+t;
			}
		}
		
		int res=0;
		for(int i=1;i<=k;i++){
			if(f[i]>res) res=f[i];
		}
		
		cout<<res<<"\n";
	}
	
	return 0;
}