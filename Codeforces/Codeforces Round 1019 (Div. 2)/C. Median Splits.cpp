#include <bits/stdc++.h>
using namespace std;

const int N=200010;
int arr[N],suf[N],minsuf[N];
int n,k;

bool check(){
	minsuf[n]=suf[n]=arr[n];
	for(int i=n-1;i>=1;i--){
		suf[i]=suf[i+1]+arr[i];
		minsuf[i]=min(minsuf[i+1],suf[i]);
	}
	int s=0;
	for(int i=1;i+2<=n;i++){
		s+=arr[i];
		if(s>=0){
			if(suf[i+1]-minsuf[i+2]>=0){
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		for(int i=1;i<=n;i++){
			if(arr[i]<=k){
				arr[i]=1;
			}else{
				arr[i]=-1;
			}
		}
		
		int a=n+1,b=-1;
		int s=0;
		for(int i=1;i<=n;i++){
			s+=arr[i];
			if(s>=0){
				a=i;
				break;
			}
		}
		s=0;
		for(int i=n;i>=1;i--){
			s+=arr[i];
			if(s>=0){
				b=i;
				break;
			}
		}
		
		if(a+1<b){
			cout<<"YES"<<"\n";
			continue;
		}
		if(check()){
			cout<<"YES"<<"\n";
			continue;
		}
		for(int i=1;i<=n/2;i++){
			swap(arr[i],arr[n-i+1]);
		}
		if(check()){
			cout<<"YES"<<"\n";
			continue;
		}
		cout<<"NO"<<"\n";
	}
	
	return 0;
}
