#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
	double init=1;
	for(int i=1;i<=365;i++){
		if(i%7==6||i%7==0){
			init*=0.99;
		}else{
			init*=1.01;
		}
	}
	
	cout<<init<<"\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T=1;
//	cin>>T;
	
	while(T--){
		solve();
	}
	
	return 0;
}
