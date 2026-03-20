#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	if(n==0){
		cout<<"0"<<endl;
		return 0;
	}
	
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	
	vector<int> power2(32);
	for(int i=0;i<=31;i++) power2[i]=1<<i;
	
	int ans=0;
	for(int i=0;i<n;i++){
		bool found=false;
		int max_sum=a[i]+a.back();
		int max_d=0;
		while(max_d<=31&&power2[max_d]<=max_sum) max_d++;
		max_d=min(max_d,31);
		
		for(int d=0;d<=max_d;d++){
			int target=power2[d]-a[i];
			if(target<0) continue;
			
			auto l=lower_bound(a.begin(),a.end(),target);
			if(l==a.end()||*l!=target) continue;
			
			auto r=upper_bound(a.begin(),a.end(),target);
			int cnt=r-l;
			
			if(target!=a[i]){
				found=true;
				break;
			}else{
				if(cnt>=2){
					found=true;
					break;
				}
			}
		}
		if(!found) ans++;
	}
	
	cout<<ans<<endl;
	
	return 0;
}