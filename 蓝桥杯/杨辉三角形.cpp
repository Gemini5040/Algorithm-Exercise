#include <bits/stdc++.h>
using namespace std;

long long A[21];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n;
	cin>>n;
	
	A[0]=1LL;
	for(int i=1;i<=20;i++){
		long long tmp=1LL;
		for(int j=2;j<=i;j++){
			tmp*=j;
		}
		A[i]=tmp;
	}
	
	//for(int i=1;i<=20;i++) cout<<A[i]<<" ";
	
	int i=0,j=0;
	for(i=0;i<=20;i++){
		int flag=0;
		for(j=0;j<=(i+1)/2;j++){
			long long num=A[i]/(A[j]*A[i-j]);
			if(num==n){
				flag=1;
				break;
			}
		}
		if(flag) break;
	}
	
	int ans=(1+i)*i/2+j+1;
	cout<<ans<<endl;
	
	return 0;
}