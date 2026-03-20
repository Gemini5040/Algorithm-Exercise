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
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a.begin(),a.end(),less<int>());
		
		int flag=1;
		int ma=0;
		for(int i=0;i<n;i+=2){
			if(max(ma,a[i])!=max(ma,a[i+1])){
				flag=0;
				break;
			}
			ma=max(ma,a[i])+1;
		}
		
		cout<<(flag?"YES":"NO")<<"\n";
	}
	
	return 0;
}
