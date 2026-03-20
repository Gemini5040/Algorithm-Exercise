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
		
		vector<int> a(n,0);
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i]=(int)abs(a[i]);
		}
		int a1=a[0];
		sort(a.begin(),a.end(),[&](int x,int y){return x<y;});
		
		auto pos=lower_bound(a.begin(),a.end(),a1);
		int d=pos-a.begin()+1;
		
		int mid=(n+1)>>1;
		if((n&1)==1){
			if(d<=mid){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}else{
			if(d<=mid+1){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}
	}
	
	return 0;
}
