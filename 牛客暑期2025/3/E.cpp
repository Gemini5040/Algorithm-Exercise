#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int V=5000010;
const int MAXN=1000010;
const int MAXV=V+1;
const ull H=1e9+7;

bool compose[MAXV];
ull Hash[MAXV];

void sieve(){
	vector<int> prime;
	ull ha=H;
	for(int i=2;i<=V;i++){
		if(!compose[i]){
			prime.push_back(i);
			Hash[i]=ha;
			ha*=H;
		}
		for(int j=0;j<(int)prime.size();j++){
			if(i*prime[j]>V) break;
			compose[i*prime[j]]=true;
			Hash[i*prime[j]]=Hash[i]^Hash[prime[j]];
			if(i%prime[j]==0) break;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	sieve();
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		ull h=0;
		if(n==2){
			int x,y;
			cin>>x>>y;
			cout<<(x==y?"YES":"NO")<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			h^=Hash[a];
		}
		cout<<((n&1)||h==0?"YES":"NO")<<"\n";
	}
	
	return 0;
}
