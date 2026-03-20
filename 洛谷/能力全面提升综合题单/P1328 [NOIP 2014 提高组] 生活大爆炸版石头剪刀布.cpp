#include <bits/stdc++.h>
using namespace std;

const int N=210;
int a[N],b[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,na,nb;
	cin>>n>>na>>nb;
	
	for(int i=1;i<=na;i++){
		cin>>a[i];
	}
	for(int i=1;i<=nb;i++){
		cin>>b[i];
	}
	
	for(int i=na+1;i<=n;i++){
		a[i]=a[i-na];
	}
	for(int i=nb+1;i<=n;i++){
		b[i]=b[i-nb];
	}
	
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0&&(b[i]==3||b[i]==2)) ans1++;
		else if(b[i]==0&&(a[i]==3||a[i]==2)) ans2++;
		
		if(a[i]==1&&(b[i]==0||b[i]==3)) ans1++;
		else if(b[i]==1&&(a[i]==0||a[i]==3)) ans2++;
		
		if(a[i]==2&&(b[i]==1||b[i]==4)) ans1++;
		else if(b[i]==2&&(a[i]==1||a[i]==4)) ans2++;
		
		if(a[i]==3&&(b[i]==2||b[i]==4)) ans1++;
		else if(b[i]==3&&(a[i]==2||a[i]==4)) ans2++;
		
		if(a[i]==4&&(b[i]==0||b[i]==1)) ans1++;
		else if(b[i]==4&&(a[i]==0||a[i]==1)) ans2++;
	}
	
	cout<<ans1<<" "<<ans2<<"\n";
	
	return 0;
}
