#include <bits/stdc++.h>
using namespace std;

const int N=1000010;
int a[N],b[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s1,s2;
	cin>>s1>>s2;
	
	int p1=1,p2=1;
	int cnt1=0,cnt2=0;
	for(auto ss:s1){
		if(ss=='.') a[p1++]=0,cnt1++;
		else a[p1++]=1;
	}
	for(auto ss:s2){
		if(ss=='.') b[p2++]=0,cnt2++;
		else b[p2++]=1;
	}
	
	for(int i=1;i<p1;i++){
		if(a[i]==0&&b[i]==0){
			cnt1--;
			cnt2--;
		}else{
			break;
		}
	}
	for(int i=p1-1;i>=1;i--){
		if(a[i]==0&&b[i]==0){
			cnt1--;
			cnt2--;
		}else{
			break;
		}
	}
	
	int ans=min(cnt1,cnt2);
	cout<<ans<<"\n";
	
	return 0;
}