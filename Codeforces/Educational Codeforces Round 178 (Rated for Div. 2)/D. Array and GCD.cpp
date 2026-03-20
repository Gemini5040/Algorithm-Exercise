#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int P=6000010;
const int N=400010;
vector<ll> primes(P+1);
vector<ll> sum(P+1);
vector<bool> st(P+1);
int cnt=1;

vector<ll> a(N+1),b(N+1);

void get_primes(){
	for(int i=2;i<=P;i++){
		if(!st[i]) primes[cnt++]=i;
		for(int j=1;primes[j]<=P/i;j++){
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
	for(int i=1;i<cnt;i++){
		sum[i]=sum[i-1]+primes[i];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	get_primes();
	
	int T;
	cin>>T;
	
	while(T--){
		a[0]=0,b[0]=0;
		
		int n;
		cin>>n;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a.begin()+1,a.begin()+1+n,[&](ll x,ll y){return x<y;});
		for(int i=1;i<=n;i++){
			b[i]=(a[i]+b[i-1]);
		}
		
		if(b[n]>=sum[n]) cout<<0<<"\n";
		else{
			int l=1,r=n-1;
			while(l<r){
				int mid=(l+r)>>1;
				if(b[n]-b[mid]<sum[n-mid]) l=mid+1;
				else r=mid;
			}
			cout<<l<<"\n";
		}
		
//		cout<<"---"<<primes[400000]<<"\n";
	}
	
	return 0;
}
