#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,m;
		cin>>n>>m;
		
		long long max_sum=LLONG_MIN,min_sum=LLONG_MAX;
		long long max_diff=LLONG_MIN,min_diff=LLONG_MAX;
		
		for(int i=0;i<n;i++){
			long long x,y;
			cin>>x>>y;
			
			long long sum=x+y;
			long long diff=x-y;
			
			if(sum>max_sum) max_sum=sum;
			if(sum<min_sum) min_sum=sum;
			if(diff>max_diff) max_diff=diff;
			if(diff<min_diff) min_diff=diff;
		}
		
		long long ans=LLONG_MAX;
		
		for(int i=0;i<m;i++){
			long long a,b;
			cin>>a>>b;
			
			long long sum_j=a+b;
			long long diff_j=a-b;
			
			long long c1=sum_j-min_sum;
			long long c2=max_sum-sum_j;
			long long c3=diff_j-min_diff;
			long long c4=max_diff-diff_j;
			
			long long c_max=max(max(c1,c2),max(c3,c4));
			if(c_max<ans){
				ans=c_max;
			}
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}