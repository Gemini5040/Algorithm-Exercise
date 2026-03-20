#include <bits/stdc++.h>
using namespace std;

const int N=200010;
vector<int> nums(N);
vector<int> v;
int n,k;

bool check(int target){
	int cnt=0;
	int cur_mex=0;
	for(int i=0;i<(int)v.size();i++){
		if(v[i]<(int)v.size()){
			nums[v[i]]=1;
		}
		while(nums[cur_mex]){
			cur_mex++;
		}
		if(cur_mex>=target){
			cnt++;
			for(int j=0;j<cur_mex;j++){
				nums[j]=0;
			}
			cur_mex=0;
		}
	}
	
	for(int i=0;i<(int)v.size();i++){
		nums[i]=0;
	}
	
	return cnt>=k;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		v.clear();
		
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int t;
			cin>>t;
			v.push_back(t);
		}
		
		int l=0,r=1e9;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(mid)) l=mid;
			else r=mid-1;
		}
		
		cout<<l<<"\n";
	}
	
	return 0;
}
