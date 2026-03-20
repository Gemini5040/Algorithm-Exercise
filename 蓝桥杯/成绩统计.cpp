#include <bits/stdc++.h>
using namespace std;

const int N=10010;
int a[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=60){
			cnt1++;
		}
		if(a[i]>=85){
			cnt2++;
		}
	}
	
	int ans1=round(cnt1*100.0/n);
	int ans2=round(cnt2*100.0/n);
	cout<<ans1<<"%"<<"\n";
	cout<<ans2<<"%"<<"\n";
	
	return 0;
}