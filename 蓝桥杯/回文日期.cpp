#include <bits/stdc++.h>
using namespace std;

int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int day_[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int isL(int y){
	return (y%4==0&&y%100!=0)||(y%400==0);
}

int getp(int y){
	int arr[5]={0},pos=1;
	int t=y;
	while(t){
		arr[pos++]=t%10;
		t/=10;
	}
	for(int i=1;i<=4;i++){
		y=(y*10)+arr[i];
	}
	return y;
}

int isvalid(int n){
	int y=n/10000;
	int m=(n/100)%100;
	int d=n%100;
	if(!isL(y)){
		return m>=1&&m<=12&&d>=1&&d<=day[m];
	}else{
		return m>=1&&m<=12&&d>=1&&d<=day_[m];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int st,ed;
	cin>>st>>ed;
	
	int ans=0;
	int y1=st/10000,y2=ed/10000;
	for(int i=y1;i<=y2;i++){
		int crt=getp(i);
//		cout<<crt<<"---"<<"\n";
		if(isvalid(crt)&&crt>=st&&crt<=ed){
			ans++;
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}