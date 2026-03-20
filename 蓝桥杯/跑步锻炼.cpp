#include <bits/stdc++.h>
using namespace std;

int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int day_[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int ri[100000],pos1=1;
int xingqi[100000],pos2=1;

//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	
//	for(int y=2000;y<=2020;y++){
//		int limit=12;
//		if(y==2020){
//			limit=9;
//		}
//		if(y%4==0){
//			for(int m=1;m<=limit;m++){
//				for(int d=1;d<=day_[m];d++){
//					ri[pos1++]=d;
//				}
//			}
//		}else{
//			for(int m=1;m<=limit;m++){
//				for(int d=1;d<=day[m];d++){
//					ri[pos1++]=d;
//				}
//			}
//		}
//	}
//	ri[pos1++]=1;
//	
//	int xq=6;
//	for(int i=1;i<pos1;i++){
//		xingqi[pos2++]=xq++;
//		if(xq==8){
//			xq=1;
//		}
//	}
//	
////	for(int i=1;i<pos1;i++){
////		cout<<"ri:"<<ri[i]<<"--"<<"xingqi:"<<xingqi[i]<<"\n";
////	}
//
//	int rp=0;
//	for(int i=1;i<pos1;i++){
//		if(ri[i]==1&&xingqi[i]==1){
//			rp++;
//		}
//	}
//	
//	int md=0;
//	for(int i=1;i<pos1;i++){
//		if(xingqi[i]==1){
//			md++;
//		}
//	}
//	
//	int fd=0;
//	for(int i=1;i<=pos1;i++){
//		if(ri[i]==1){
//			fd++;
//		}
//	}
//	
//	int ans=pos1-1+md+fd-rp;
//	
//	cout<<"how many days:"<<pos1-1<<"\n";
//	cout<<"how many Mondays:"<<md<<"\n";
//	cout<<"how many 1st:"<<fd<<"\n";
//	cout<<"repeat:"<<rp<<"\n";
//	cout<<"answer:"<<ans<<"\n";
//	
//	return 0;
//}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cout<<"8879"<<"\n";
	
	return 0;
}