#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		s.clear();
		s+='0';
		
		int n;
		cin>>n;
		string ts;
		cin>>ts;
		s+=ts;
		
		int ans=n;
		int lim=s.size();
		for(int i=1;i<lim;i++){
			if(s[i]!=s[i-1]) ans++;
		}
		
		int flag1=0,flag2=0;
		for(int i=0;i<lim-1;i++){
			if(flag1==0){
				if(s[i]=='0'&&s[i+1]=='1'){
					flag1=1;
				}
			}else if(flag1==1){
				if(s[i]=='1'&&s[i+1]=='0'){
					flag1=2;
				}
			}else if(flag1==2){
				if(s[i]=='0'&&s[i+1]=='1'){
					flag1=3;
					break;
				}
			}
			
			if(flag2==0){
				if(s[i]=='1'&&s[i+1]=='0'){
					flag2=1;
				}
			}else if(flag2==1){
				if(s[i]=='0'&&s[i+1]=='1'){
					flag2=2;
				}
			}else if(flag2==2){
				if(s[i]=='1'&&s[i+1]=='0'){
					flag2=3;
					break;
				}
			}
		}
		
		if(flag1==2||flag2==2){
			ans-=1;
		}else if(flag1==3||flag2==3){
			ans-=2;
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
