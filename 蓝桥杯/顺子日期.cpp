#include <bits/stdc++.h>

using namespace std;

int main(){
	int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	int cnt=0;
	for(int m=1;m<=12;m++){
		for(int d=1;d<=day[m];d++){
			int str[8]={2,0,2,2,m/10,m%10,d/10,d%10};
			for(int i=0;i<=5;i++){
				if(str[i]+1==str[i+1]&&str[i+1]+1==str[i+2]){
					cnt++;
					break;
				}
			}
		}
	}
	
	printf("%d",cnt);
	
	return 0;
}