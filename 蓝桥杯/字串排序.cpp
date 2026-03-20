#include <bits/stdc++.h>
using namespace std;

int getl(int x){
	double tmp=(1+(double)sqrt(1+8*x))/2.0;
	int res=(int)tmp;
	if((double)tmp-(int)tmp>0) res++;
	return res;
}

int arr[10000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
//	int T;
//	cin>>T;
//	
//	while(T--){
//		fill(arr,arr+10000,0);
		
		int n;
		cin>>n;
		
		string s;
	
		int l=getl(n);
		int gap=(l*(l-1))/2-n;
		
		for(int i=0;i<l;i++){
			arr[i]=i;
		}
		
		int p=1;
		for(int i=1;i<=gap;i++){
			arr[p]-=1;
			p+=2;
		}
		
		int last=0;
		int ad=0;
		for(int i=0;i<l;i++){
			if(arr[i]>last){
				ad++;
			}
			s[i]='a'+ad;
			last=arr[i];
		}
		
		int sum=0;
		for(int i=0;i<l;i++){
			sum+=arr[i];
		}
		if(sum>n){
			char tmp_ch=s[l-1];
			s[l-1]=s[l-2];
			s[l-2]=tmp_ch;
		}
		
		for(int i=l-1;i>=0;i--){
			cout<<s[i];
		}
//		cout<<"\n";
//	}
	
	return 0;
}