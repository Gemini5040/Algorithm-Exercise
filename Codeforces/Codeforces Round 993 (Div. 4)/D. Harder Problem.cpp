#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		vector<int> a(n+1),b(n+1);
		for(int i=1;i<=n;i++){
			int t;
			cin>>t;
			if(!b[t]){
				a[i]=t;
				b[t]=1;
			}
		}
		queue<int> q;
		for(int i=1;i<=n;i++){
			if(!b[i]){
				q.push(i);
			}
		}
		for(int i=1;i<=n;i++){
			if(!a[i]){
				a[i]=q.front();
				q.pop();
			}
		}
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" \n"[i==n];
		}
	}
	
	return 0;
}