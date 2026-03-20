#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s,t;
	while(cin>>t){
		int flag=0;
		int pos=0;
		for(int i=0;i<(int)t.size();i++){
			if(t[i]=='E'){
				flag=1;
				pos=i;
				break;
			}
		}
		if(flag){
			for(int i=0;i<pos;i++){
				s+=t[i];
			}
			break;
		}else{
			s+=t;
		}
	}
	
	if((int)s.size()==0){
		cout<<"0:0"<<"\n\n"<<"0:0"<<"\n";
		return 0;
	}
	
	int w=0,l=0;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]=='W'){
			w++;
		}else if(s[i]=='L'){
			l++;
		}
		if(((w>=11||l>=11)&&(int)abs(w-l)>=2)&&i!=(int)s.size()-1){
			cout<<w<<":"<<l<<"\n";
			w=0,l=0;
		}else if(((w>=11||l>=11)&&(int)abs(w-l)>=2)&&i==(int)s.size()-1){
			cout<<w<<":"<<l<<"\n";
			cout<<"0:0"<<"\n";
		}else if(i==(int)s.size()-1){
			cout<<w<<":"<<l<<"\n";
		}
	}
	cout<<"\n";
	
	w=0,l=0;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]=='W'){
			w++;
		}else if(s[i]=='L'){
			l++;
		}
		if(((w>=21||l>=21)&&(int)abs(w-l)>=2)&&i!=(int)s.size()-1){
			cout<<w<<":"<<l<<"\n";
			w=0,l=0;
		}else if(((w>=21||l>=21)&&(int)abs(w-l)>=2)&&i==(int)s.size()-1){
			cout<<w<<":"<<l<<"\n";
			cout<<"0:0"<<"\n";
		}else if(i==(int)s.size()-1){
			cout<<w<<":"<<l<<"\n";
		}
	}
	
	return 0;
}
