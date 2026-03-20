#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
using ll=long long;

void solve(){
	int m,x;
	cin>>m>>x;
	vector<ll> c(m);
	for(int i=0;i<m;i++){
		cin>>c[i];
	}
	ll budget=0;
	priority_queue<ll> max_heap;
	for(int i=0;i<m;i++){
		if(budget>=c[i]){
			max_heap.push(c[i]);
			budget-=c[i];
		}else if(!max_heap.empty()&&max_heap.top()>c[i]){
			budget+=max_heap.top()-c[i];
			max_heap.pop();
			max_heap.push(c[i]);
		}
		budget+=x;
	}
	cout<<max_heap.size()<<endl;
}

signed main(){
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