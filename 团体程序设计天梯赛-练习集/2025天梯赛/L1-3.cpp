#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T,S,t;
	cin>>T>>S>>t;
	if(T>35&&S&&t>=33){
		cout<<"Bu Tie"<<"\n"<<T<<"\n";
	}else if(T>35&&!S&&t>=33){
		cout<<"Shi Nei"<<"\n"<<T<<"\n";
	}else if((!(T>35&&t>=33))&&S){
		cout<<"Bu Re"<<"\n"<<t<<"\n";
	}else if((!(T>35&&t>=33))&&!S){
		cout<<"Shu Shi"<<"\n"<<t<<"\n";
	}
	
	return 0;
}
