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
		
		vector<int> a(n+1,0);
		vector<int> b(10010,0);
		int ma=0;
		int pos=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[a[i]]++;
			if(a[i]>ma){
				ma=a[i];
				pos=i;
			}
		}
		
		if(b[ma]<n){
			cout<<"YES"<<"\n";
			for(int i=1;i<=n;i++){
				if(i!=pos){
					cout<<1<<" ";
				}else{
					cout<<2<<" ";
				}
			}
			cout<<"\n";
		}else if(b[ma]==n){
			cout<<"NO"<<"\n";
		}
	}
	
	return 0;
}
