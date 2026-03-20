#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool valid(int x){
	int p=(x&1);
	while(x){
		if((x&1)!=p) return false;
		x/=10;
		p=1-p;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	int num=1;
	for(int i=10;i<=1000000000;i++){
		if(valid(i)){
			num++;
			if(num>n){
				cout<<i<<"\n";
				break;
			}
		}
	}
	
	return 0;
}
