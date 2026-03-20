#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=200010;
ll a[N];
ll cnt[30];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		fill(a,a+N,0LL);
		fill(cnt,cnt+30,0LL);
		
		int n;
		cin>>n;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=0;j<30;j++){
				cnt[j]+=((a[i]>>j)&1);
			}
		}
		
		ll ans=0;
		for(int i=1;i<=n;i++){
			ll tmp=0;
			for(int j=0;j<30;j++){
				if((a[i]>>j)&1){
					tmp+=(1<<j)*(n-cnt[j]);
				}else{
					tmp+=(1<<j)*cnt[j];
				}
			}
			ans=max(ans,tmp);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}