#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		
		vector<int> a(n);
		for(auto &x:a) cin>>x;
		
		int best_diff=0,L=0,R=0;
		for(int i=0;i<n;i++){
			int cnt_greater=0,cnt_less=0;
			for(int j=i+1;j<n;j++){
				cnt_greater+=a[j]>a[i];
				cnt_less+=a[j]<a[i];
				
				if(cnt_less-cnt_greater>best_diff){
					best_diff=cnt_less-cnt_greater;
					L=i,R=j;
				}
			}
		}
		
		cout<<L+1<<" "<<R+1<<"\n";
	}
	
	return 0;
}
