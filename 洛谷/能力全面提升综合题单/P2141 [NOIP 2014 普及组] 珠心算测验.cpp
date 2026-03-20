#include <bits/stdc++.h>
using namespace std;

int a[110],b[20010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=1;
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&b[a[i]+a[j]]){
				ans++;
				b[a[i]+a[j]]=0;
			}
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
