#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
	int64 n;
	cin>>n;
	n/=1000;
	
	int h=(n%86400)/3600;
	int m=(n%3600)/60;
	int s=n%60;
	
	printf("%02d:%02d:%02d",h,m,s);
	
	return 0;
}