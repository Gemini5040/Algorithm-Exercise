#include <bits/stdc++.h>
using namespace std;

int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int day_l[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int get_palindrome(int x){
	int num[4],pos=0;
	int t=x;
	while(t){
		num[pos++]=t%10;
		t/=10;
	}
	for(int i=0;i<4;i++){
		x=x*10+num[i];
	}
	return x;
}

bool is_leap_year(int y){
	return (y%4==0&&y%100!=0)||(y%400==0);
}

bool is_valid(int x){
	int y=x/10000,m=(x/100)%100,d=x%100;
	if(is_leap_year(y)) return m>=1&&m<=12&&d>=1&&d<=day_l[m];
	else return m>=1&&m<=12&&d>=1&&d<=day[m];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int st,ed;
	cin>>st>>ed;
	
	int ans=0;
	int sty=st/10000,edy=ed/10000;
	for(int y=sty;y<=edy;y++){
		int pld=get_palindrome(y);
		if(is_valid(pld)&&pld>=st&&pld<=ed){
			ans++;
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
