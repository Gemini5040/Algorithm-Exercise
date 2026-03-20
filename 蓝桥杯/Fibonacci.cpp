#include <bits/stdc++.h>
using namespace std;

int f[10010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int pos=0;
	
	f[1]=1,f[2]=1;
	for(int i=3;i<=10000;i++){
		f[i]=f[i-1]+f[i-2];
		if(f[i]>20211001){
			pos=i;
			break;
		}
	}
	
	cout<<pos<<"\n";
	
	return 0;
}