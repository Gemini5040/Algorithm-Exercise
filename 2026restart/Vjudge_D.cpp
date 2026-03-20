#include <bits/stdc++.h>
using namespace std;

const int N=200010;

int n;
int a[N],b[N],c[N],ra[N],rb[N];

void solve(){
	cin>>n;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		cin>>c[i];
		a[i]=b[i]=0;
		ra[i+1]=rb[i+1]=1;
		v.push_back(make_pair(c[i],i));
	}
	sort(v.rbegin(),v.rend());

	for(int i=0;i<n;i++){
		int k=v[i].second;
		if(ra[c[k]]==1) a[k]=c[k],ra[c[k]]--;
		else b[k]=c[k],rb[c[k]]--;
	}

	int r1=n,r2=n;
	for(int i=0;i<n;i++){
		int k=v[i].second;
		if(a[k]==0){
			while(ra[r1]==0) r1--;
			ra[r1]--;
			if(r1>b[k]){
				cout<<"NO"<<"\n";
				return;
			}
			a[k]=r1--;
		}else{
			while(rb[r2]==0) r2--;
			rb[r2]--;
			if(r2>a[k]){
				cout<<"NO"<<"\n";
				return;
			}
			b[k]=r2--;
		}
	}
	for(int i=1;i<=n;i++){
		if(ra[i]!=0||rb[i]!=0){
			cout<<"NO"<<"\n";
			return;
		}
	}
	cout<<"YES"<<"\n";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" \n"[i==n-1];
	}
	for(int i=0;i<n;i++){
		cout<<b[i]<<" \n"[i==n-1];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T=1;
	cin>>T;

	while(T--){
		solve();
	}

	return 0;
}