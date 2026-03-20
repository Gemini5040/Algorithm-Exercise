#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	vector<int> id(n,0),idcnt(n+10,0);
	for(int i=0;i<n;i++){
		cin>>id[i];
		idcnt[id[i]]++;
	}

	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		if(idcnt[i]==1){
			sum1++;
		}else if(idcnt[i]>2){
			sum2+=(idcnt[i]-2);
		}
	}
	
	int ans=0;
	if(sum2>=sum1){
		ans=sum2;
	}if(sum2<sum1){
		ans=sum2+(sum1-sum2)/2;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
