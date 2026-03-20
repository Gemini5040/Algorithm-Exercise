#include <bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
const int N=1000010;
int n;
int a[N],first[N],num[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		memset(a,0,sizeof(a));
		memset(first,0,sizeof(first));
		memset(num,0,sizeof(num));
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=n;i>=1;i--){
			if(a[i]==0){
				num[i]=num[i+1];
				continue;
			}
			num[i]=num[i+1]+(first[a[i]]==0);
			first[a[i]]=i;
		}
		
		long long ans=0;
		int last0=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				last0=i;
				continue;
			}
			if(first[a[i]]<last0){
				ans+=num[i+1];
				first[a[i]]=INF;
			}
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}