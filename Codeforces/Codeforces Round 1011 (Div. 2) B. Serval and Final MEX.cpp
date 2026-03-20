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
		
		vector<int> a(n+1,0);
		int flag=0;
		int st=0,ed=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0){
				flag++;
				if(flag==1) st=i;
				ed=i;
			}
		}
		
		if(flag==0){
			cout<<1<<"\n";
			cout<<1<<" "<<n<<"\n";
		}else{
			int mid=(1+n)>>1;
			if(ed<=mid){
				cout<<2<<"\n";
				cout<<1<<" "<<mid<<"\n";
				cout<<1<<" "<<n-mid+1<<"\n";
			}else if(st<=mid&&ed>mid){
				cout<<3<<"\n";
				cout<<1<<" "<<mid<<"\n";
				cout<<2<<" "<<n-mid+1<<"\n";
				cout<<1<<" "<<2<<"\n";
			}else if(st>mid){
				cout<<2<<"\n";
				cout<<mid+1<<" "<<n<<"\n";
				cout<<1<<" "<<mid+1<<"\n";
			}
		}
	}
	
	return 0;
}
