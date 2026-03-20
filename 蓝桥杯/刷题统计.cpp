#include <bits/stdc++.h>

#define ULL unsigned long long

using namespace std;

int main(){
	ULL a,b,n;
	cin>>a>>b>>n;
	
	ULL num_a_week=a*5+b*2;
	
	ULL week=n/num_a_week;
	ULL rest=n%num_a_week;
	
	int restDay=0;
	ULL nn[8]={0,a,a,a,a,a,b,b};
	if(rest>0){
		for(int i=1;i<=7;i++){
			restDay++;
			if(rest<=nn[i]) break;
			rest-=nn[i];
		}
	}
	
	ULL days=week*7+restDay;
	cout<<days<<endl;
	
	return 0;
}