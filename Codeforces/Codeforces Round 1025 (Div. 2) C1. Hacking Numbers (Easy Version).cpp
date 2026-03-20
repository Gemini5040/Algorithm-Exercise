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
		
		cout<<"digit"<<endl;
		int x;
		cin>>x;
		
		cout<<"digit"<<endl;
		cin>>x;
		
		for(int i=8;i>=1;i>>=1){
			cout<<"add"<<" "<<-i<<endl;
			cin>>x;
		}
		
		cout<<"add"<<" "<<n-1<<endl;
		cin>>x;
		
		cout<<"!"<<endl;
		cin>>x;
		assert(x==1);
	}
	
	return 0;
}
