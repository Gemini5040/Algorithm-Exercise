#include <bits/stdc++.h>
using namespace std;

int budget[13];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for(int i=1;i<=12;i++){
		cin>>budget[i];
	}
	
	int x=0;
	int rest=0;
	int saving=0;
	for(int i=1;i<=12;i++){
		rest+=300;
		rest-=budget[i];
		if(rest>=0){
			int t=(rest/100)*100;
			saving+=t;
			rest-=t;
		}else{
			x=i;
			break;
		}
	}
	
	if(x) cout<<-x<<"\n";
	else cout<<rest+saving*1.2<<"\n";
	
	return 0;
}
