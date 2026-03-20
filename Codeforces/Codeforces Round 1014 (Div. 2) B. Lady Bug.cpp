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
		
		string s1,s2;
		cin>>s1>>s2;
		
		int co1=0,ce1=0,co2=0,ce2=0;
		for(int i=1;i<=n;i++){
			int a=s1[i-1]-'0';
			if(a){
				if((i&1)==1){
					co1++;
				}else{
					ce1++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			int b=s2[i-1]-'0';
			if(!b){
				if((i&1)==1){
					co2++;
				}else{
					ce2++;
				}
			}
		}
		
//		cout<<"--"<<co1+ce1<<" "<<co2+ce2<<"\n";
		
		int flag=1;
		if(co1+co2>co2+ce2){
			flag=0;
		}else{
			if(!(co2>=ce1&&ce2>=co1)){
				flag=0;
			}
		}
		
		if(flag) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
	
	return 0;
}
